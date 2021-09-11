
#ifndef MY_GPIO_H_
#define MY_GPIO_H_

#include "my_stm32f446xx.h"

/*
 * @def_group GPIO_Pin_x defines the GPIO_InitTypeDef_t->pin_Number
 *
 */

#define GPIO_PIN_0	 ((uint16_t)0x0001)		/* Pin 0   Selected */
#define GPIO_PIN_1	 ((uint16_t)0x0002)		/* Pin 1   Selected */
#define GPIO_PIN_2	 ((uint16_t)0x0004)		/* Pin 2   Selected */
#define GPIO_PIN_3	 ((uint16_t)0x0008)		/* Pin 3   Selected */
#define GPIO_PIN_4	 ((uint16_t)0x0010)		/* Pin 4   Selected */
#define GPIO_PIN_5	 ((uint16_t)0x0020)		/* Pin 5   Selected */
#define GPIO_PIN_6	 ((uint16_t)0x0040)		/* Pin 6   Selected */
#define GPIO_PIN_7	 ((uint16_t)0x0080)		/* Pin 7   Selected */
#define GPIO_PIN_8	 ((uint16_t)0x0100)		/* Pin 8   Selected */
#define GPIO_PIN_9	 ((uint16_t)0x0200)		/* Pin 9   Selected */
#define GPIO_PIN_10	 ((uint16_t)0x0400)		/* Pin 10  Selected */
#define GPIO_PIN_11	 ((uint16_t)0x0800)		/* Pin 11  Selected */
#define GPIO_PIN_12	 ((uint16_t)0x1000)		/* Pin 12  Selected */
#define GPIO_PIN_13	 ((uint16_t)0x2000)		/* Pin 13  Selected */
#define GPIO_PIN_14	 ((uint16_t)0x4000)		/* Pin 14  Selected */
#define GPIO_PIN_15	 ((uint16_t)0x8000)		/* Pin 15  Selected */
#define GPIO_PIN_All ((uint16_t)0xFFFF)		/* Pin All Selected */

#define MAX_PIN_NUMBER	 16U				/* Max Pin Number   */

/*
 * @def_group GPIO_MODE_X defines the GPIO_InitTypeDef_t->Mode
 *
 */

#define GPIO_MODE_INPUT		0x0U	/* Input Mode Selected			    */
#define GPIO_MODE_OUTPUT	0x1U	/* Output Mode Selected 			*/
#define GPIO_MODE_AF		0x2U	/* Alternate Function Mode Selected */
#define GPIO_MODE_ANALOG	0x3U	/* Analog Mode Selected 			*/


/*
 * @def_group GPIO_OTYPE_X defines the GPIO_InitTypeDef_t->Otype
 *
 */

#define GPIO_OTYPE_PP		0x0U	/* Push-Pull  Mode Selected */
#define GPIO_OTYPE_OD		0x1U	/* Open-Drain Mode Selected */


/*
 * @def_group GPIO_PUPD_x defines the GPIO_InitTypeDef_t->PuPd
 *
 */

#define GPIO_PUPD_NOPULL	 0x0U	/* No Pull   Mode Selected */
#define GPIO_PUPD_PULLUP	 0x1U	/* Pull Up   Mode Selected */
#define GPIO_PUPD_PULLDOWN	 0x2U	/* Pull Down Mode Selected */


/*
 * @def_group GPIO_SPEED_X defines the GPIO_InitTypeDef_t->Speed
 *
 */

#define	GPIO_SPEED_FREQ_LOW			0x0U	/* IO works at 2 MHz, please refer to the product datasheet 	   */
#define	GPIO_SPEED_FREQ_MEDIUM		0x1U	/* range 12,5 MHz to 50 MHz, please refer to the product datasheet */
#define	GPIO_SPEED_FREQ_HIGH		0x2U	/* range 25 MHz to 100 MHz, please refer to the product datasheet  */
#define	GPIO_SPEED_FREQ_VERY_HIGH	0x3U	/* range 50 MHz to 200 MHz, please refer to the product datasheet  */



/*
 * @def_group GPIO_Alternate_x defines the GPIO_InitTypeDef_t->Alternate
 *
 */

#define GPIO_AF0	(0x0U)
#define GPIO_AF1	(0x1U)
#define GPIO_AF2	(0x2U)
#define GPIO_AF3	(0x3U)
#define GPIO_AF4	(0x4U)
#define GPIO_AF5	(0x5U)
#define GPIO_AF6	(0x6U)
#define GPIO_AF7	(0x7U)
#define GPIO_AF8	(0x8U)
#define GPIO_AF9	(0x9U)
#define GPIO_AF10	(0xAU)
#define GPIO_AF11	(0xBU)
#define GPIO_AF12	(0xCU)
#define GPIO_AF13	(0xDU)
#define GPIO_AF14	(0xEU)
#define GPIO_AF15	(0xFU)





typedef enum
{

	GPIO_Pin_Reset = 0x0U,
	GPIO_Pin_Set = (!GPIO_Pin_Reset)

}GPIO_PinState_t;

typedef struct
{
	uint32_t	pin_Number;		/*!> pin_Number macros defines in @def_group GPIO_Pin_x		  */
	uint32_t	Mode;			/*!> Mode		macros defines in @def_group GPIO_Mode_x 	  */
	uint32_t	Otype;			/*!> Otype		macros defines in @def_group GPIO_Otype_x	  */
	uint32_t	PuPd;			/*!> PuPd 		macros defines in @def_group GPIO_PuPd_x	  */
	uint32_t	Speed;			/*!> Speed 		macros defines in @def_group GPIO_Speed_x	  */
	uint32_t	Alternate;		/*!> Alternate 	macros defines in @def_group GPIO_Alternate_x */

}GPIO_InitTypeDef_t;

void GPIO_Init(GPIO_TypeDef_t *GPIOx, GPIO_InitTypeDef_t *GPIO_Init);
void GPIO_Write_Pin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber, GPIO_PinState_t pinState);
GPIO_PinState_t GPIO_Read_Pin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber);
void GPIO_LockPin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber);
void GPIO_TogglePin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber);

#endif /* MY_GPIO_H_ */
