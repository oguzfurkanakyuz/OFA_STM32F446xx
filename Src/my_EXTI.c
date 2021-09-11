#include "my_EXTI.h"

/**
  * @brief  EXTI_Init makes available interrupt for valid GPIO port and line number
  *
  * @param  EXTI_InitStruct : User configuration struct
  *
  * @retval void.
  */

void EXTI_Init(EXTI_InitTypeDef_t *EXTI_InitStruct){

	uint32_t tempValue = 0;

	tempValue = (uint32_t)EXTI_BASE_ADDR;

	EXTI->IMR &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);
	EXTI->EMR &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);

	if(EXTI_InitStruct->LineCmd != DISABLE)
	{

		tempValue += EXTI_InitStruct->EXTI_Mode;

		*( (__IO uint32_t*)tempValue ) = (0x1U << EXTI_InitStruct->EXTI_LineNumber);

		tempValue = (uint32_t)EXTI_BASE_ADDR;

		EXTI->RTSR &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);
		EXTI->FTSR &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);

		if(EXTI_InitStruct->EXTI_TriggerSelection == EXTI_TRIGGER_RF)
		{

			EXTI->RTSR |= (0x1U << EXTI_InitStruct->EXTI_LineNumber);
			EXTI->FTSR |= (0x1U << EXTI_InitStruct->EXTI_LineNumber);

		}
		else
		{

			tempValue += EXTI_InitStruct->EXTI_TriggerSelection;

			*((__IO uint32_t*)tempValue) |= (0x1U << EXTI_InitStruct->EXTI_LineNumber);
		}
	}
	else{

		tempValue = (uint32_t)EXTI_BASE_ADDR;
		tempValue += EXTI_InitStruct->EXTI_Mode;

		*((__IO uint32_t*)tempValue) &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);

	}

}


/**
  * @brief  GPIO_LineConfig configures the port and pin for SYSCFG.
  *
  * @param  PortSource determines the port A-G @def_group PORT_Source.
  * @param  LineSource determines the pin 0-15 @def_group LINE_Source.
  *
  * @retval void.
  */

void EXTI_LineConfig(uint8_t PortSource, uint8_t LineSource){

	uint32_t tempValue;

	tempValue = SYSCFG->EXTICR[LineSource >> 2U];
	tempValue &= ~(0xFU << (LineSource & 0x3U) * 4);
	tempValue |= (PortSource << (LineSource & 0x3U) * 4);

	SYSCFG->EXTICR[LineSource >> 2U] = tempValue;
}

/**
  * @brief  NVIC_EnableInterrupt enables interrupt to the desired line
  *
  * @param  IRQNumber = IRQNumber of line
  *
  * @retval void.
  */
void NVIC_EnableInterrupt(IRQ_TypeDef_t IRQNumber){

	uint32_t tempValue = 0;

	tempValue =  *( (IRQNumber >> 5U) + NVIC_ISER0 );
	tempValue &= ~( 0x1U << (IRQNumber & 0x1FU) );
	tempValue |= ( 0x1U << (IRQNumber & 0x1FU) );
	*( (IRQNumber >> 5U) + NVIC_ISER0 ) = tempValue;

}

