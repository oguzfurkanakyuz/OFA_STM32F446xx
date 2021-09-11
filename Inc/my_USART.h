#ifndef MY_USART_H_
#define MY_USART_H_

#include "my_stm32f446xx.h"

#define __USART_BRR_OVERSAMPLING_8( __PCLOCK__, __BAUDRATE__)	(1)
#define __USART_BRR_OVERSAMPLING_16( __PCLOCK__, __BAUDRATE__)	(1)

/*
 * @def_group MODE_Types
 */

#define USART_MODE_TX		( (uint32_t)(0x00000008) )
#define USART_MODE_RX		( (uint32_t)(0x00000004) )
#define USART_MODE_TX_RX	( (uint32_t)(0x0000000C) )

/*
 *	@def_group WordLength_Types
 */

#define USART_WORDLENGTH_8BIT	( (uint32_t)(0x00000000) )
#define USART_WORDLENGTH_9BIT	( (uint32_t)(0x00001000) )


/*
 * @def_group ParityBit_Types
 */

#define USART_PARITY_NONE		( (uint32_t)(0x00000000) )
#define USART_PARITY_EVEN		( (uint32_t)(0x00000400) )
#define USART_PARITY_ODD		( (uint32_t)(0x00000600) )

/*
 * @def_group StopBit_Types
 */

#define USART_STOPBITS_1		( (uint32_t)(0x00000000) )
#define USART_STOPBITS_0_5		( (uint32_t)(0x00001000) )
#define USART_STOPBITS_2		( (uint32_t)(0x00002000) )
#define USART_STOPBITS_1_5		( (uint32_t)(0x00003000) )


/*
 * @def_group OverSampling_Types
 */

#define USART_OVERSAMPLING_16	( (uint32_t)(0x00000000) )
#define USART_OVERSAMPLING_8	( (uint32_t)(0x00008000) )

/*
 * @def_group HardwareFlowControl_Types
 */

#define USART_HW_NONE			( (uint32_t)(0x00000000) )
#define USART_HW_CTS			( (uint32_t)(0x00000200) )
#define USART_HW_RTS			( (uint32_t)(0x00000100) )
#define USART_HW_CTS_RTS		( (uint32_t)(0x00000300) )

typedef enum
{
	USART_BUS_FREE = 0x0U,
	USART_BUS_Tx   = 0x1U,
	USART_BUS_Rx   = 0x2U

}USART_BusState_t;

typedef struct{

	uint32_t Mode;					/*!< Transmission and Reception Modes @def_group MODE_Types  	  */
	uint32_t BaudRate;
	uint32_t WordLength;			/*!< 8-bit or 9-bit Selection  @def_group WordLength_Types        */
	uint32_t OverSampling;			/*!<  OverSampling Modes       @def_group OverSampling_Types 	  */
	uint32_t Parity;				/*!< Parity Bit Enable/Disable  @def_group ParityBit_Types   	  */
	uint32_t StopBits;				/*!< Stop Bit Selection  @def_group StopBit_Types          		  */
	uint32_t HardWareFlowControl;	/*!< Hardware Flow Control @def_group HardwareFlowControl_Types   */

}USART_InitTypeDef_t;


typedef struct __USART_HandleTypedef_t
{
	USART_TypeDef_t *Instance;
	USART_InitTypeDef_t Init;
	uint8_t *pTxBuffer;
	uint16_t TxBufferSize;
	uint8_t TxStatus;
	void (*TxISR_Function)(struct __USART_HandleTypedef_t *USART_Handle);
	uint8_t *pRxBuffer;
	uint16_t RxBufferSize;
	uint8_t RxStatus;
	void (*RxISR_Function)(struct __USART_HandleTypedef_t *USART_Handle);

}USART_HandleTypedef_t;


void USART_Init(USART_HandleTypedef_t *USART_Handle);
void USART_TransmitData(USART_HandleTypedef_t *USART_Handle, uint8_t *pData, uint16_t DataSize);
void USART_RecieveData(USART_HandleTypedef_t *USART_Handle, uint8_t *pBuffer, uint16_t DataSize);
void USART_TransmitData_IT(USART_HandleTypedef_t *USART_Handle, uint8_t *pData, uint16_t DataSize);
void USART_ReceiveData_IT(USART_HandleTypedef_t *USART_Handle, uint8_t *pData, uint16_t DataSize);
void USART_PeriphCmd(USART_HandleTypedef_t *USART_Handle, FunctionalState_t stateOfUSART);
void USART_InterruptHandler(USART_HandleTypedef_t *USART_Handle);
USART_FlagStatus_t USART_GetFlagStatus(USART_HandleTypedef_t *USART_Handle, uint16_t USART_Flag);


#endif /* MY_USART_H_ */
