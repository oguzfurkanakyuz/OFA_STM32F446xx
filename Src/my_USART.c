
#include "my_USART.h"

static void closeUSART_ISR_Tx(USART_HandleTypedef_t *USART_Handle)
{
	USART_Handle->TxBufferSize = 0;
	USART_Handle->pTxBuffer = NULL;
	USART_Handle->TxStatus = USART_BUS_FREE;

	USART_Handle->Instance->CR1 &= ~(0x1U << USART_CR1_TxEIE);

}

static void closeUSART_ISR_Rx(USART_HandleTypedef_t *USART_Handle)
{
	USART_Handle->RxBufferSize = 0;
	USART_Handle->pRxBuffer = NULL;
	USART_Handle->RxStatus = USART_BUS_FREE;

	USART_Handle->Instance->CR1 &= ~(0x1U << USART_CR1_RxEIE);


}

static void USART_SendWidth_IT(USART_HandleTypedef_t *USART_Handle)
{

	if( (USART_Handle->Init.WordLength == USART_WORDLENGTH_9BIT) && (USART_Handle->Init.Parity == USART_PARITY_NONE) )
	{
		uint16_t *p16BitsData = (uint16_t*)(USART_Handle->pTxBuffer);
		USART_Handle->Instance->DR = (uint16_t)(*p16BitsData & (uint16_t)0x01FF);
		USART_Handle->pTxBuffer += sizeof(uint16_t);
		USART_Handle->TxBufferSize -= 2;

	}
	else
	{
		USART_Handle->Instance->DR = (uint8_t)(*(USART_Handle->pTxBuffer) & (uint8_t)0x00FF );
		USART_Handle->pTxBuffer++;
		USART_Handle->TxBufferSize--;
	}

	if(USART_Handle	->TxBufferSize == 0)
	{
		closeUSART_ISR_Tx(USART_Handle);
	}

}

static void USART_ReceiveWidth_IT(USART_HandleTypedef_t *USART_Handle)
{
	uint16_t *p16BitsBuffer;
	uint8_t *p8BitsBuffer;

	if( (USART_Handle->Init.WordLength) == USART_WORDLENGTH_9BIT && (USART_Handle->Init.Parity == USART_PARITY_NONE) )
	{
		p16BitsBuffer= (uint16_t*)USART_Handle->pRxBuffer;
		p8BitsBuffer = NULL;
	}
	else
	{
		p8BitsBuffer = (uint8_t*)USART_Handle->pRxBuffer;
		p16BitsBuffer = NULL;
	}

	if(p8BitsBuffer == NULL)
	{
		*p16BitsBuffer = (uint16_t)(USART_Handle->Instance->DR & 0x01FFU);
		USART_Handle->pRxBuffer += sizeof(uint16_t);
		USART_Handle->RxBufferSize -= 2;
	}
	else
	{
		if( (USART_Handle->Init.WordLength) == USART_WORDLENGTH_9BIT && (USART_Handle->Init.Parity != USART_PARITY_NONE) )
		{
			*p8BitsBuffer = (uint8_t)(USART_Handle->Instance->DR & 0x00FFU);
			USART_Handle->pRxBuffer++;
			USART_Handle->RxBufferSize--;

		}
		else if( (USART_Handle->Init.WordLength) == USART_WORDLENGTH_8BIT && (USART_Handle->Init.Parity != USART_PARITY_NONE) )
		{
			*p8BitsBuffer = (uint8_t)(USART_Handle->Instance->DR & 0x00FFU);
			USART_Handle->pRxBuffer++;
			USART_Handle->RxBufferSize--;
		}
		else
		{
			*p8BitsBuffer = (uint8_t)(USART_Handle->Instance->DR & 0x007FU);
			USART_Handle->pRxBuffer++;
			USART_Handle->RxBufferSize--;

		}
	}

	if(USART_Handle->RxBufferSize == 0)
	{
		closeUSART_ISR_Rx(USART_Handle);
	}

}

USART_FlagStatus_t USART_GetFlagStatus(USART_HandleTypedef_t *USART_Handle, uint16_t USART_Flag)
{

	return (USART_Handle->Instance->SR & USART_Flag) ? USART_FLAG_SET : USART_FLAG_RESET;

}

void USART_Init(USART_HandleTypedef_t *USART_Handle)
{

	uint32_t temp_Reg = 0;
	uint32_t periph_clock = 0;
	uint32_t mantissa_part = 0;
	uint32_t fraction_part = 0;
	uint32_t USART_DIV_Value = 0;
	uint32_t tempValue = 0;

	/* CR1 Configuration ******************************************************************** */

	temp_Reg = USART_Handle->Instance->CR1;
	temp_Reg |= (USART_Handle->Init.OverSampling) | (USART_Handle->Init.WordLength) | (USART_Handle->Init.Mode) /
				(USART_Handle->Init.Parity);

	USART_Handle->Instance->CR1 = temp_Reg;

	/* CR2 Configuration ******************************************************************** */

	temp_Reg = USART_Handle->Instance->CR2;
	temp_Reg &= ~(0x3U << USART_CR2_STOPBIT);
	temp_Reg |= (USART_Handle->Init.StopBits);

	USART_Handle->Instance->CR2 = temp_Reg;

	/* CR3 Configuration ******************************************************************** */

	temp_Reg = USART_Handle->Instance->CR3;
	temp_Reg |= (USART_Handle->Init.HardWareFlowControl);

	USART_Handle->Instance->CR3 = temp_Reg;

	/* Baud Rate Configuratiom ************************************************************** */

	if(USART_Handle->Instance == USART1 || USART_Handle->Instance == USART6)
	{
		periph_clock = RCC_GetPClock2();

	}
	else
	{
		periph_clock = RCC_GetPClock1();
	}


	if(USART_Handle->Init.OverSampling == USART_OVERSAMPLING_8)
	{
		USART_DIV_Value = __USART_BRR_OVERSAMPLING_8(periph_clock, USART_Handle->Init.BaudRate);
		mantissa_part = ( USART_DIV_Value / 100 );
		fraction_part = (USART_DIV_Value) - (mantissa_part * 100U);

		fraction_part = ( ((fraction_part * 8U) +50U) / 100U) & 0x07U;
	}
	else
	{
		USART_DIV_Value = __USART_BRR_OVERSAMPLING_16(periph_clock, USART_Handle->Init.BaudRate);
		mantissa_part = ( USART_DIV_Value / 100 );
		fraction_part = (USART_DIV_Value) - (mantissa_part * 100U);

		fraction_part = ( ((fraction_part * 8U) +50U) / 100U) & 0x0FU;
	}

	tempValue |= (mantissa_part << 4U);
	tempValue |= (fraction_part << 0U);
}


void USART_TransmitData(USART_HandleTypedef_t *USART_Handle, uint8_t *pData, uint16_t DataSize)
{

	uint16_t *data16Bits;

	if ( (USART_Handle->Init.WordLength == USART_WORDLENGTH_9BIT) && (USART_Handle->Init.Parity == USART_PARITY_NONE) )
	{
		data16Bits = (uint16_t*)pData;
	}
	else
	{
		data16Bits = NULL;
	}

	while(DataSize > 0)
	{
		while( !(USART_GetFlagStatus(USART_Handle, USART_FLAG_TXE)) );

		if(data16Bits == NULL)	// data has 8-bit
		{
			USART_Handle->Instance->DR = (uint8_t)(*pData & 0xFFU);
			pData++;
			DataSize--;
		}

		else					// data has 9-bit
		{
			USART_Handle->Instance->DR = (uint16_t)(*data16Bits & 0x01FFU);
			data16Bits++;
			DataSize -= 2;
		}
	}

	while( !(USART_GetFlagStatus(USART_Handle, USART_FLAG_TC)) );

}

void USART_RecieveData(USART_HandleTypedef_t *USART_Handle, uint8_t *pBuffer, uint16_t DataSize)
{

	uint16_t *p16BitsBuffer;
	uint8_t *p8BitsBuffer;

	if ( (USART_Handle->Init.WordLength == USART_WORDLENGTH_9BIT) && (USART_Handle->Init.Parity == USART_PARITY_NONE) )
	{
		p16BitsBuffer = (uint16_t*)pBuffer;
		p8BitsBuffer = NULL;
	}
	else
	{
		p8BitsBuffer = (uint8_t*)pBuffer;
		p16BitsBuffer = NULL;
	}

	while(DataSize > 0)
	{
		while( !(USART_GetFlagStatus(USART_Handle, USART_FLAG_RxNE)) );

		if(p8BitsBuffer == NULL)
		{
			*p16BitsBuffer = (uint16_t)(USART_Handle->Instance->DR & 0x01FFU);
			p16BitsBuffer++;
			DataSize -= 2;
		}
		else
		{
			if(USART_Handle->Init.WordLength == USART_WORDLENGTH_9BIT && (USART_Handle->Init.Parity != USART_PARITY_NONE))
			{
				*p8BitsBuffer = (uint8_t)(USART_Handle->Instance->DR & 0x00FFU);
				p8BitsBuffer++;
				DataSize--;

			}
			else if(USART_Handle->Init.WordLength == USART_WORDLENGTH_8BIT && (USART_Handle->Init.Parity != USART_PARITY_NONE))
			{
				*p8BitsBuffer = (uint8_t)(USART_Handle->Instance->DR & 0x00FFU);
				p8BitsBuffer++;
				DataSize--;
			}
			else
			{
				*p8BitsBuffer = (uint8_t)(USART_Handle->Instance->DR & 0x007FU);
				p8BitsBuffer++;
				DataSize--;
			}
		}
	}




}

void USART_TransmitData_IT(USART_HandleTypedef_t *USART_Handle, uint8_t *pData, uint16_t DataSize)
{

	USART_BusState_t usart_BusState = USART_Handle->TxStatus;

	if(usart_BusState != USART_BUS_Tx)
	{
		USART_Handle->pTxBuffer = (uint8_t*)pData;
		USART_Handle->TxBufferSize = (uint16_t)DataSize;
		USART_Handle->TxStatus = USART_BUS_Tx;
		USART_Handle->TxISR_Function = USART_SendWidth_IT;

		USART_Handle->Instance->CR1 = (0x1U << USART_CR1_TxEIE);

	}

}

void USART_ReceiveData_IT(USART_HandleTypedef_t *USART_Handle, uint8_t *pData, uint16_t DataSize)
{
	USART_BusState_t usart_BusState = USART_Handle->RxStatus;

	if(usart_BusState != USART_BUS_Rx)
	{
		USART_Handle->pRxBuffer = (uint8_t*)pData;
		USART_Handle->RxBufferSize = (uint16_t)DataSize;
		USART_Handle->RxStatus = USART_BUS_Rx;
		USART_Handle->RxISR_Function = USART_ReceiveWidth_IT;

		USART_Handle->Instance->CR1 = (0x1U << USART_CR1_RxEIE);

	}

}

void USART_InterruptHandler(USART_HandleTypedef_t *USART_Handle)
{
	uint8_t flagValue = 0;
	uint8_t interruptValue = 0;

	flagValue = (uint8_t)( (USART_Handle->Instance->SR >> 7U) & 0x1U );
	interruptValue = (uint8_t)( (USART_Handle->Instance->CR1 >> 7U) & 0x1U );

	if( flagValue && interruptValue)
	{
		USART_Handle->TxISR_Function(USART_Handle);
	}

	flagValue = (uint8_t)( (USART_Handle->Instance->SR >> 7U) & 0x1U );
	interruptValue = (uint8_t)( (USART_Handle->Instance->CR1 >> 7U) & 0x1U );

	if( flagValue && interruptValue)
	{
		USART_Handle->RxISR_Function(USART_Handle);
	}


}

void USART_PeriphCmd(USART_HandleTypedef_t *USART_Handle, FunctionalState_t stateOfUSART)
{
	if(stateOfUSART == ENABLE)
	{
		USART_Handle->Instance->CR1 |= USART_ENABLE;
	}


}


