/*
 * my_stm32f446xx.h
 *
 *  Created on: 17 Haz 2021
 *      Author: furkan
 */

#ifndef MY_STM32F446XX_H_
#define MY_STM32F446XX_H_

#include <stdint.h>
#include "rcc.h"


#define __IO volatile

#define SET_BIT(REG, BIT)		( (REG) |=  (BIT) )
#define CLEAR_BIT(REG, BIT)		( (REG) &= ~(BIT) )
#define READ_BIT(REG, BIT)		( (REG) &   (BIT) )
#define UNUSED(x)				(void)x


/*
 * 	Memory Base Addresses
 */

#define FLASH_BASE_ADDR			(0X80000000UL)	/* Flash Memory Base Address (up to 1MB) */
#define SRAM1_BASE_ADDR			(0x20000000UL)	/* SRAM1 Base Address (112KB)			 */
#define SRAM2_BASE_ADDR			(0x2001C000UL)	/* SRAM2 Base Address (16KB) 			 */


/*
 * 	Peripheral Base Addresses
 */

#define PERIPH_BASE_ADDR		(0x40000000UL)						/* Base Address for All Peripherals */

#define APB1_BASE_ADDR			PERIPH_BASE_ADDR					/* Base Address of APB1 Bus 		*/
#define APB2_BASE_ADDR			(PERIPH_BASE_ADDR + 0x00010000UL)	/* Base Address of APB2 Bus 		*/
#define AHB1_BASE_ADDR			(PERIPH_BASE_ADDR + 0x00020000UL)	/* Base Address of AHB1 Bus		    */
#define AHB2_BASE_ADDR			(PERIPH_BASE_ADDR + 0x10000000UL)	/* Base Address of AHB2 Bus 		*/


/*
 * 	APB1 Base Addresses
 */

#define TIM2_BASE_ADDR			APB1_BASE_ADDR					/* TIM2 Base Address   */
#define TIM3_BASE_ADDR			(APB1_BASE_ADDR + 0x0400UL)		/* TIM3 Base Address   */
#define TIM4_BASE_ADDR			(APB1_BASE_ADDR + 0x0800UL)		/* TIM4 Base Address   */
#define TIM5_BASE_ADDR			(APB1_BASE_ADDR + 0x0C00UL)		/* TIM5 Base Address   */
#define TIM6_BASE_ADDR			(APB1_BASE_ADDR + 0x1000UL)		/* TIM6 Base Address   */
#define TIM7_BASE_ADDR			(APB1_BASE_ADDR + 0x1400UL)		/* TIM7 Base Address   */
#define TIM12_BASE_ADDR			(APB1_BASE_ADDR + 0x1800UL)		/* TIM12 Base Address  */
#define TIM13_BASE_ADDR			(APB1_BASE_ADDR + 0x1C00UL)		/* TIM13 Base Address  */
#define TIM14_BASE_ADDR			(APB1_BASE_ADDR + 0x2000UL)		/* TIM14 Base Address  */

#define SPI2_BASE_ADDR			(APB1_BASE_ADDR + 0x3800UL)		/* SPI2 Base Address   */
#define SPI3_BASE_ADDR			(APB1_BASE_ADDR + 0x3C00UL)		/* SPI3 Base Address   */

#define USART2_BASE_ADDR		(APB1_BASE_ADDR + 0x4400UL)		/* USART2 Base Address */
#define USART3_BASE_ADDR		(APB1_BASE_ADDR + 0x4800UL)		/* USART3 Base Address */
#define UART4_BASE_ADDR			(APB1_BASE_ADDR + 0x4C00UL)		/* UART4 Base Address  */
#define UART5_BASE_ADDR			(APB1_BASE_ADDR + 0x5000UL)		/* UART5 Base Address  */

#define I2C1_BASE_ADDR			(APB1_BASE_ADDR + 0x5400UL)		/* I2C1 Base Address   */
#define I2C2_BASE_ADDR			(APB1_BASE_ADDR + 0x5800UL)		/* I2C2 Base Address   */
#define I2C3_BASE_ADDR			(APB1_BASE_ADDR + 0x5C00UL)		/* I2C3 Base Address   */


/*
 * 	APB2 Base Addresses
 */

#define TIM1_BASE_ADDR			APB2_BASE_ADDR					/* TIM1 Base Address   */
#define TIM8_BASE_ADDR			(APB2_BASE_ADDR + 0x0400UL) 	/* TIM8 Base Address   */
#define TIM9_BASE_ADDR			(APB2_BASE_ADDR + 0x4000UL)		/* TIM8 Base Address   */
#define TIM10_BASE_ADDR			(APB2_BASE_ADDR + 0x4400UL) 	/* TIM8 Base Address   */
#define TIM11_BASE_ADDR			(APB2_BASE_ADDR + 0x4800UL) 	/* TIM8 Base Address   */

#define USART1_BASE_ADDR		(APB2_BASE_ADDR + 0x1000UL)		/* USART1 Base Address */
#define USART6_BASE_ADDR		(APB2_BASE_ADDR + 0x1400UL)		/* USART6 Base Address */

#define SPI1_BASE_ADDR			(APB2_BASE_ADDR + 0x3000UL)		/* SPI1 Base Address   */
#define SPI4_BASE_ADDR			(APB2_BASE_ADDR + 0x3400UL)		/* SPI4 Base Address   */

#define SYSCFG_BASE_ADDR		(APB2_BASE_ADDR + 0x3800UL)		/* SYSCFG Base Address */
#define EXTI_BASE_ADDR			(APB2_BASE_ADDR + 0x3C00UL)		/* EXTI Base Address   */


/*
 * 	AHB1 Base Address
 */

#define GPIOA_BASE_ADDR			AHB1_BASE_ADDR					/* GPIOA Base Address */
#define GPIOB_BASE_ADDR			(AHB1_BASE_ADDR	+ 0X0400UL)		/* GPIOB Base Address */
#define GPIOC_BASE_ADDR			(AHB1_BASE_ADDR	+ 0X0800UL)		/* GPIOC Base Address */
#define GPIOD_BASE_ADDR			(AHB1_BASE_ADDR	+ 0X0C00UL)		/* GPIOD Base Address */
#define GPIOE_BASE_ADDR			(AHB1_BASE_ADDR	+ 0X1000UL)		/* GPIOE Base Address */
#define GPIOF_BASE_ADDR			(AHB1_BASE_ADDR	+ 0X1400UL)		/* GPIOF Base Address */
#define GPIOG_BASE_ADDR			(AHB1_BASE_ADDR	+ 0X1800UL)		/* GPIOG Base Address */
#define GPIOH_BASE_ADDR			(AHB1_BASE_ADDR	+ 0X1C00UL)		/* GPIOH Base Address */

#define CRC_BASE_ADDR			(AHB1_BASE_ADDR + 0x3000UL)		/* CRC Base Address   */
#define RCC_BASE_ADDR			(AHB1_BASE_ADDR + 0x3800UL)		/* RCC Base Address	  */

#define DMA1_BASE_ADDR			(AHB1_BASE_ADDR + 0x6000UL)		/* DMA1 Base Address  */
#define DMA2_BASE_ADDR			(AHB1_BASE_ADDR + 0x6400UL)		/* DMA2 Base Address  */



/*
 * 	Peripheral Structure Definitions
 */

typedef struct
{

	__IO uint32_t MODER;		/*!< GPIO port mode register,					Address offset: 0x00 */
	__IO uint32_t OTYPER;		/*!< GPIO port output type register,			Address offset: 0x04 */
	__IO uint32_t OSPEEDR;		/*!< GPIO port output speed register,			Address offset: 0x08 */
	__IO uint32_t PUPDR;		/*!< GPIO port pull-up/pull-down register,		Address offset: 0x0C */
	__IO uint32_t IDR;			/*!< GPIO port input data register,				Address offset: 0x10 */
	__IO uint32_t ODR;			/*!< GPIO port output data register,			Address offset: 0x14 */
	__IO uint32_t BSRR;			/*!< GPIO port bit set/reset register,			Address offset: 0x18 */
	__IO uint32_t LCKR;			/*!< GPIO port configuration lock register,		Address offset: 0x1C */
	__IO uint32_t AFR[2];		/*!< GPIO alternate function high register,		Address offset: 0x20 */

}GPIO_TypeDef_t;

typedef struct
{

	__IO uint32_t CR;			/*!< clock control register 							   	 	 Address offset: 0x00 */
	__IO uint32_t PLLCFGR;		/*!< PLL configuration register									 Address offset: 0x04 */
	__IO uint32_t CFGR;			/*!< clock configuration register								 Address offset: 0x08 */
	__IO uint32_t CIR;			/*!< clock interrupt register									 Address offset: 0x0C */
	__IO uint32_t AHB1RSTR;		/*!< AHB1 peripheral reset register 							 Address offset: 0x10 */
	__IO uint32_t AHB2RSTR;		/*!< AHB2 peripheral reset register 							 Address offset: 0x14 */
	__IO uint32_t AHB3RSTR;		/*!< AHB3 peripheral reset register 							 Address offset: 0x18 */
	__IO uint32_t RESERVED0;	/*!< Reserved, 0x1C																	  */
	__IO uint32_t APB1RSTR; 	/*!< APB1 peripheral reset register 							 Address offset: 0x20 */
	__IO uint32_t APB2RSTR;		/*!< APB2 peripheral reset register 							 Address offset: 0x24 */
	__IO uint32_t RESERVED1[2]; /*!< Reserved, 0x28, 0x2C															  */
	__IO uint32_t AHB1ENR;		/*!< AHB1 peripheral clock enable register 						 Address offset: 0x30 */
	__IO uint32_t AHB2ENR;		/*!< AHB2 peripheral clock enable register 						 Address offset: 0x34 */
	__IO uint32_t AHB3ENR;		/*!< AHB3 peripheral clock enable register 						 Address offset: 0x38 */
	__IO uint32_t RESERVED2;	/*!< Reserved, 0x3C											    	 				  */
	__IO uint32_t APB1ENR;		/*!< APB1 peripheral clock enable register 						 Address offset: 0x40 */
	__IO uint32_t APB2ENR;		/*!< APB2 peripheral clock enable register 						 Address offset: 0x44 */
	__IO uint32_t RESERVED3[2];	/*!< Reserved, 0x48, 0x4C															  */
	__IO uint32_t AHB1LPENR;	/*!< AHB1 peripheral clock enable in low power mode register 	 Address offset: 0x50 */
	__IO uint32_t AHB2LPENR;	/*!< AHB2 peripheral clock enable in low power mode register 	 Address offset: 0x54 */
	__IO uint32_t AHB3LPENR;	/*!< AHB3 peripheral clock enable in low power mode register 	 Address offset: 0x58 */
	__IO uint32_t RESERVED4;	/*!< Reserved, 0x5C																	  */
	__IO uint32_t APB1LPENR;	/*!< APB1 peripheral clock enable in low power mode register 	 Address offset: 0x60 */
	__IO uint32_t APB2LPENR;	/*!< APB2 peripheral clock enable in low power mode register 	 Address offset: 0x64 */
	__IO uint32_t RESERVED5[2];	/*!< Reserved, 0x68, 0x6C															  */
	__IO uint32_t BDCR;			/*!< Backup domain control register 						  	 Address offset: 0x70 */
	__IO uint32_t CSR;			/*!< clock control & status register 							 Address offset: 0x74 */
	__IO uint32_t RESERVED6[2]; /*!< Reserved, 0x78																	  */
	__IO uint32_t SSCGR;		/*!< spread spectrum clock generation register 					 Address offset: 0x80 */
	__IO uint32_t PLLI2SCFGR;	/*!< PLLI2S configuration register 								 Address offset: 0x84 */
	__IO uint32_t PLLSAICFGR;	/*!< PLL configuration register 							   	 Address offset: 0x88 */
	__IO uint32_t DCKCFGR;		/*!< Dedicated Clock Configuration Register 				 	 Address offset: 0x8C */
	__IO uint32_t CKGATENR;		/*!< clocks gated enable register 							 	 Address offset: 0x90 */
	__IO uint32_t DCKCFGR2;		/*!< dedicated clocks configuration register 2 				 	 Address offset: 0x94 */


}RCC_TypeDef_t;


#define GPIOA		( (GPIO_TypeDef_t *)(GPIOA_BASE_ADDR) )
#define GPIOB		( (GPIO_TypeDef_t *)(GPIOB_BASE_ADDR) )
#define GPIOC		( (GPIO_TypeDef_t *)(GPIOC_BASE_ADDR) )
#define GPIOD		( (GPIO_TypeDef_t *)(GPIOD_BASE_ADDR) )
#define GPIOE		( (GPIO_TypeDef_t *)(GPIOE_BASE_ADDR) )
#define GPIOF		( (GPIO_TypeDef_t *)(GPIOF_BASE_ADDR) )
#define GPIOG		( (GPIO_TypeDef_t *)(GPIOG_BASE_ADDR) )
#define GPIOH		( (GPIO_TypeDef_t *)(GPIOH_BASE_ADDR) )

#define RCC			( (RCC_TypeDef_t *)(RCC_BASE_ADDR)    )

#define RCC_AHB1ENR_GPIOAEN_Pos		(0U)								/*!< RCC AHB1ENR Register GPIOAEN Register Bit Position */
#define RCC_AHB1ENR_GPIOAEN_Msk		(0x1UL << RCC_AHB1ENR_GPIOAEN_Pos)	/*!< 0x00000001 										*/
#define RCC_AHB1ENR_GPIOAEN			RCC_AHB1ENR_GPIOAEN_Msk				/*!< RCC AHB1ENR Register GPIOAEN Register  Macro       */
#define RCC_AHB1ENR_GPIOBEN_Pos		(1U)								/*!< RCC AHB1ENR Register GPIOBEN Register Bit Position */
#define RCC_AHB1ENR_GPIOBEN_Msk		(0x1UL << RCC_AHB1ENR_GPIOBEN_Pos)	/*!< 0x00000002											*/
#define RCC_AHB1ENR_GPIOBEN			RCC_AHB1ENR_GPIOBEN_Msk				/*!< RCC AHB1ENR Register GPIOBEN Register  Macro       */
#define RCC_AHB1ENR_GPIOCEN_Pos		(2U)								/*!< RCC AHB1ENR Register GPIOCEN Register Bit Position */
#define RCC_AHB1ENR_GPIOCEN_Msk		(0x1UL << RCC_AHB1ENR_GPIOCEN_Pos)	/*!< 0x00000004											*/
#define RCC_AHB1ENR_GPIOCEN			RCC_AHB1ENR_GPIOCEN_Msk				/*!< RCC AHB1ENR Register GPIOCEN Register  Macro       */
#define RCC_AHB1ENR_GPIODEN_Pos		(3U)								/*!< RCC AHB1ENR Register GPIODEN Register Bit Position */
#define RCC_AHB1ENR_GPIODEN_Msk		(0x1UL << RCC_AHB1ENR_GPIODEN_Pos)	/*!< 0x00000008											*/
#define RCC_AHB1ENR_GPIODEN			RCC_AHB1ENR_GPIODEN_Msk				/*!< RCC AHB1ENR Register GPIODEN Register  Macro       */
#define RCC_AHB1ENR_GPIOEEN_Pos		(4U)								/*!< RCC AHB1ENR Register GPIOEEN Register Bit Position */
#define RCC_AHB1ENR_GPIOEEN_Msk		(0x1UL << RCC_AHB1ENR_GPIOEEN_Pos)	/*!< 0x00000010											*/
#define RCC_AHB1ENR_GPIOEEN			RCC_AHB1ENR_GPIOEEN_Msk				/*!< RCC AHB1ENR Register GPIOEEN Register  Macro       */
#define RCC_AHB1ENR_GPIOFEN_Pos		(5U)								/*!< RCC AHB1ENR Register GPIOFEN Register Bit Position */
#define RCC_AHB1ENR_GPIOFEN_Msk		(0x1UL << RCC_AHB1ENR_GPIOFEN_Pos)	/*!< 0x000000020										*/
#define RCC_AHB1ENR_GPIOFEN			RCC_AHB1ENR_GPIOFEN_Msk				/*!< RCC AHB1ENR Register GPIOFEN Register  Macro       */
#define RCC_AHB1ENR_GPIOGEN_Pos		(6U)								/*!< RCC AHB1ENR Register GPIOGEN Register Bit Position */
#define RCC_AHB1ENR_GPIOGEN_Msk		(0x1UL << RCC_AHB1ENR_GPIOGEN_Pos)	/*!< 0x000000040										*/
#define RCC_AHB1ENR_GPIOGEN			RCC_AHB1ENR_GPIOGEN_Msk				/*!< RCC AHB1ENR Register GPIOGEN Register  Macro       */
#define RCC_AHB1ENR_GPIOHEN_Pos		(7U)								/*!< RCC AHB1ENR Register GPIOHEN Register Bit Position */
#define RCC_AHB1ENR_GPIOHEN_Msk		(0x1UL << RCC_AHB1ENR_GPIOHEN_Pos)	/*!< 0x000000080										*/
#define RCC_AHB1ENR_GPIOHEN			RCC_AHB1ENR_GPIOHEN_Msk				/*!< RCC AHB1ENR Register GPIOHEN Register  Macro       */





#endif /* MY_STM32F446XX_H_ */
