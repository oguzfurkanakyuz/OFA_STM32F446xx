/*
 * my_SPI.h
 *
 *  Created on: 27 Tem 2021
 *      Author: furkan
 */

#ifndef MY_SPI_H_
#define MY_SPI_H_

#include "my_stm32f446xx.h"


typedef enum{

	SPI_BUS_FREE = 0x0U,
	SPI_BUS_BUSY_TX = 0x1U,
	SPI_BUS_BUSY_RX = 0x2U

}SPI_BusStatus_t;


/*
 *
 * 	@defgroup SPI_MODE
 */

#define SPI_SLAVE   		( (uint32_t)(0x00000000) )  /*!< 0000 0000 0000 0000 0000 0000 0000 0000 */
#define SPI_MASTER			( (uint32_t)(0x00000004) )  /*!< 0000 0000 0000 0000 0000 0000 0000 0100 */


/*
 *
 * 	@defgroup SPI_CPHA
 */

#define SPI_CPHA_FIRST      ( (uint32_t)(0x00000000) )  /*!< 0000 0000 0000 0000 0000 0000 0000 0000 */
#define SPI_CPHA_SECOND 	( (uint32_t)(0x00000001) )	/*!< 0000 0000 0000 0000 0000 0000 0000 0001 */

/*
 *
 * 	@defgroup SPI_CPHA
 */

#define SPI_CPOL_LOW      ( (uint32_t)(0x00000000) )  /*!< 0000 0000 0000 0000 0000 0000 0000 0000 */
#define SPI_CPOL_HIGH	  ( (uint32_t)(0x00000002) )  /*!< 0000 0000 0000 0000 0000 0000 0000 0010 */


/*
 *
 * 	 @defgroup SPI_BaudRate
 */

#define SPI_BAUDRATE_DIV2	( (uint32_t)(0x00000000) ) /*!< 0000 0000 0000 0000 0000 0000 0000 0000 */
#define SPI_BAUDRATE_DIV4	( (uint32_t)(0x00000008) ) /*!< 0000 0000 0000 0000 0000 0000 0000 1000 */
#define SPI_BAUDRATE_DIV8	( (uint32_t)(0x00000010) ) /*!< 0000 0000 0000 0000 0000 0000 0001 0000 */
#define SPI_BAUDRATE_DIV16	( (uint32_t)(0x00000018) ) /*!< 0000 0000 0000 0000 0000 0000 0001 1000 */
#define SPI_BAUDRATE_DIV32	( (uint32_t)(0x00000020) ) /*!< 0000 0000 0000 0000 0000 0000 0010 0000 */
#define SPI_BAUDRATE_DIV64	( (uint32_t)(0x00000028) ) /*!< 0000 0000 0000 0000 0000 0000 0010 1000 */
#define SPI_BAUDRATE_DIV128	( (uint32_t)(0x00000030) ) /*!< 0000 0000 0000 0000 0000 0000 0011 0000 */
#define SPI_BAUDRATE_DIV256	( (uint32_t)(0x00000038) ) /*!< 0000 0000 0000 0000 0000 0000 0011 1000 */


/*
 *
 * 	 @defgroup SPI_FRAME_FORMAT
 */

#define SPI_SSM_DISABLE		( (uint32_t)(0x00000000) ) /*!< 0000 0000 0000 0000 0000 0000 0000 0000 */
#define SPI_SSM_ENABLE		( (uint32_t)(0x00000300) ) /*!< 0000 0000 0000 0000 0000 0011 0000 0000 */

/*
 *
 * 	 @defgroup SPI_DFF
 */

#define SPI_DFF_8BITS 		( (uint32_t)(0x00000000) ) /*!< 0000 0000 0000 0000 0000 0000 0000 0000 */
#define SPI_DFF_16BITS		( (uint32_t)(0x00000800) ) /*!< 0000 0000 0000 0000 0000 1000 0000 0000 */


/*
 *
 * 	 @defgroup BUS_CONFIG
 */

#define SPI_FULL_DUBLEX 			( (uint32_t)(0x00000000) ) /*!< 0000 0000 0000 0000 0000 0000 0000 0000 */
#define SPI_RECEIVE_ONLY 			( (uint32_t)(0x00000400) ) /*!< 0000 0000 0000 0000 0000 0100 0000 0000 */
#define SPI_HALF_DUBLEX_RECIVE 		( (uint32_t)(0x00008000) ) /*!< 0000 0000 0000 0000 1000 0000 0000 0000 */
#define SPI_HALF_DUBLEX_TRANSMIT	( (uint32_t)(0x0000C000) ) /*!< 0000 0000 0000 0000 1100 0000 0000 0000 */



/*
 *
 * 	 @defgroup SPI_FRAME_FORMAT
 */

#define SPI_FRAMEFORMAT_MSB	( (uint32_t)(0x00000000) ) /*!< 0000 0000 0000 0000 0000 0000 0000 0000 */
#define SPI_FRAMEFORMAT_LSB	( (uint32_t)(0x00000080) ) /*!< 0000 0000 0000 0000 0000 0000 1000 0000 */

typedef struct{

	uint32_t Mode;			/*!< Master/Slave selection for SPI @defgroup SPI_MODE      */
	uint32_t CPHA;			/*!< Clock phase configuration for SPI @defgroup SPI_CPHA   */
	uint32_t CPOL;			/*!< Clock polarity configuration for SPI @defgroup SPI_COL */
	uint32_t BaudRate;		/*!< BaudRate values for SPI @defgroup SPI_BaudRate         */
	uint32_t SSM_Cmd;		/*!< Software slave management for SPI @defgroup SSM_VALUES */
	uint32_t DFF_Format;	/*!< Data frame format @defgroup SPI_DFF		            */
	uint32_t BusConfig;		/*!< Half/Full dublex selection @defgroup BUS_CONFIG		*/
	uint32_t FrameFormat;   /*!< Frame format @defgroup SPI_FRAME_FORMAT	            */

}SPI_InitTypeDef_t;


typedef struct __SPI_HandleTypeDef_t
{

	SPI_TypeDef_t *Instance;
	SPI_InitTypeDef_t Init;
	uint8_t *pTxDataAddr;
	uint16_t TxDataSize;
	uint8_t busStateTx;
	void(*TxISRFunction)(struct __SPI_HandleTypeDef_t *SPI_Handle);
	uint8_t busStateRx;
	uint8_t *pRxDataAddr;
	uint16_t RxDataSize;
	void(*RxISRFunction)(struct __SPI_HandleTypeDef_t *SPI_Handle);

}SPI_HandleTypeDef_t;


void SPI_Init(SPI_HandleTypeDef_t *SPI_Handle);
void SPI_PeriphCmd(SPI_HandleTypeDef_t *SPI_Handle, FunctionalState_t SPI_State);
void SPI_TransmitData(SPI_HandleTypeDef_t *SPI_Handle, uint8_t *pData, uint16_t sizeOfData);
void SPI_ReceiveData(SPI_HandleTypeDef_t *SPI_Handle, uint8_t *RxBuffer, uint16_t sizeOfData);
void SPI_TransmitData_IT(SPI_HandleTypeDef_t *SPI_Handle, uint8_t *pData, uint16_t sizeOfData);
void SPI_ReceiveData_IT(SPI_HandleTypeDef_t *SPI_Handle, uint8_t *RxBuffer, uint16_t sizeOfData);
void SPI_InterruptHandler(SPI_HandleTypeDef_t *SPI_Handle);
SPI_FlagStatus_t SPI_GetFlagStatus(SPI_HandleTypeDef_t *SPI_Handle, uint16_t SPI_Flag);

#endif /* MY_SPI_H_ */
