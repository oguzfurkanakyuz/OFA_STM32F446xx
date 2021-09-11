
#ifndef MY_EXTI_H_
#define MY_EXTI_H_

#include "my_stm32f446xx.h"



/*
 *	@def_group PORT_Source
 */

#define EXTI_PortSource_GPIOA	( (uint8_t)(0x0) )
#define EXTI_PortSource_GPIOB	( (uint8_t)(0x1) )
#define EXTI_PortSource_GPIOC	( (uint8_t)(0x2) )
#define EXTI_PortSource_GPIOD	( (uint8_t)(0x3) )
#define EXTI_PortSource_GPIOE	( (uint8_t)(0x4) )
#define EXTI_PortSource_GPIOF	( (uint8_t)(0x5) )
#define EXTI_PortSource_GPIOG	( (uint8_t)(0x6) )


/*
 *	@def_group LINE_Source
 */

#define EXTI_LineSource_0		( (uint8_t)(0U) )
#define EXTI_LineSource_1		( (uint8_t)(1U) )
#define EXTI_LineSource_2		( (uint8_t)(2U) )
#define EXTI_LineSource_3		( (uint8_t)(3U) )
#define EXTI_LineSource_4		( (uint8_t)(4U) )
#define EXTI_LineSource_5		( (uint8_t)(5U) )
#define EXTI_LineSource_6		( (uint8_t)(6U) )
#define EXTI_LineSource_7		( (uint8_t)(7U) )
#define EXTI_LineSource_8		( (uint8_t)(8U) )
#define EXTI_LineSource_9		( (uint8_t)(9U) )
#define EXTI_LineSource_10		( (uint8_t)(10U) )
#define EXTI_LineSource_11		( (uint8_t)(11U) )
#define EXTI_LineSource_12		( (uint8_t)(12U) )
#define EXTI_LineSource_13		( (uint8_t)(13U) )
#define EXTI_LineSource_14		( (uint8_t)(14U) )
#define EXTI_LineSource_15		( (uint8_t)(15U) )


/*
 *	@def_group EXTI_Mode
 */

#define EXTI_MODE_INTERRUPT		(0x00U)
#define EXTI_MODE_EVENT			(0x04U)


/*
 *	@def_group EXTI_Trigger
 */

#define EXTI_TRIGGER_RISING		(0x08U)
#define EXTI_TRIGGER_FALLING    (0x0CU)
#define EXTI_TRIGGER_RF			(0x10U)



typedef struct{

	uint8_t EXTI_LineNumber;			/*!< EXTI Line Numbers @def_group LINE_Source 		*/
	uint8_t EXTI_Mode;					/*!< EXTI mode values @def_group EXTI_Mode 			*/
	uint8_t EXTI_TriggerSelection;		/*!< EXTI Trigger Mode @def_group EXTI_Trigger_Mode */
	FunctionalState_t LineCmd;			/*!< Mask or Unmasked the line number 				*/

}EXTI_InitTypeDef_t;

void EXTI_LineConfig(uint8_t PortSource, uint8_t LineSource);
void EXTI_Init(EXTI_InitTypeDef_t *EXTI_InitStruct);
void NVIC_EnableInterrupt(uint8_t IRQNumber);



#endif /* MY_EXTI_H_ */
