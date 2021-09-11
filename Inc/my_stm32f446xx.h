/*
 * my_stm32f446xx.h
 *
 *  Created on: 17 Haz 2021
 *      Author: furkan
 */

#ifndef MY_STM32F446XX_H_
#define MY_STM32F446XX_H_

#include <stdint.h>
#include <string.h>
#include <stddef.h>


#define __IO volatile

#define SET_BIT(REG, BIT)		( (REG) |=  (BIT) )
#define CLEAR_BIT(REG, BIT)		( (REG) &= ~(BIT) )
#define READ_BIT(REG, BIT)		( (REG) &   (BIT) )
#define UNUSED(x)				(void)x


#define __USART_DIV_VALUE_16(__CLOCK__, __BAUDRATE__) 	( 25 * (__CLOCK__) ) / ( 4 * (__BAUDRATE___) )
#define __USART_DIV_VALUE_8(__CLOCK__, __BAUDRATE__) 	( 25 * (__CLOCK__) ) / ( 2 * (__BAUDRATE___) )
/*
 *  ENABLE, DISABLE Macros
 */

typedef enum{

	DISABLE  = 0x0U,
	ENABLE = (!DISABLE)

}FunctionalState_t;


/*
 *  IRQ Numbers of MCU == Vector Table
 */

typedef enum{

	EXTI0_IRQNumber = 6,
	EXTI1_IRQNumber = 7,
	EXTI2_IRQNumber = 8,
	EXTI3_IRQNumber = 9,
	EXTI4_IRQNumber = 10,
	SPI1_IRQNumber  = 35,
	USART2_IRQNumber = 38


}IRQ_TypeDef_t;

/*
 * SPI flag macros
 */

typedef enum{

	SPI_FLAG_RESET = 0x0U,

	SPI_FLAG_SET = !(SPI_FLAG_RESET)
}SPI_FlagStatus_t;

typedef enum{

	USART_FLAG_RESET = 0x0U,

	USART_FLAG_SET = !(USART_FLAG_RESET)

}USART_FlagStatus_t;


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
#define TIM9_BASE_ADDR			(APB2_BASE_ADDR + 0x4000UL)		/* TIM9 Base Address   */
#define TIM10_BASE_ADDR			(APB2_BASE_ADDR + 0x4400UL) 	/* TIM10 Base Address  */
#define TIM11_BASE_ADDR			(APB2_BASE_ADDR + 0x4800UL) 	/* TIM11 Base Address  */

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
 * 	NVIC Base Address
 */
#define	NVIC_ISER0				( (uint32_t *)(0xE000E100) )	/* NVIC ISER0 Initial Address */

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

typedef struct{

	__IO uint32_t MEMRMP;		 /*!< SYSCFG memory remap register 					  Address Offset = 0x00	    */
	__IO uint32_t PMC;			 /*!< SYSCFG peripheral mode configuration register    Address Offset = 0x04    */
	__IO uint32_t EXTICR[4];	 /*!< SYSCFG external interrupt configuration register Address Offset = 0x08 	*/
		 uint32_t RESERVED[2];   /*!< Reserved 0x18 and 0x1C												    */
	__IO uint32_t CMPCR;		 /*!< Compensation cell control register 			  Address Offset = 0x20     */
		 uint32_t RESERVED1[2];  /*!< Reserved 0x24 and 0x28 												    */
	__IO uint32_t CFGR;			 /*!< SYSCFG configuration register 					  Address Offset = 0x2C */

}SYSCFG_TypeDef_t;

typedef struct{

	__IO uint32_t IMR;		 /*!< EXTI Interrupt mask register 				  Address Offset = 0x00 */
	__IO uint32_t EMR;		 /*!< EXTI Event mask register					  Address Offset = 0x04 */
	__IO uint32_t RTSR;	 	 /*!< EXTI Rising trigger selection register 	  Address Offset = 0x08	*/
	__IO uint32_t FTSR;		 /*!< EXTI Falling trigger selection register	  Address Offset = 0x0C	*/
	__IO uint32_t SWIER;	 /*!< EXTI Software interrupt event register 	  Address Offset = 0x10 */
	__IO uint32_t PR;		 /*!< EXTI Pending register 					  Address Offset = 0x14	*/

}EXTI_TypeDef_t;

typedef struct{

	__IO uint32_t CR1;		/*!< I2C Control register 1 			  Address Offset = 0x00 */
	__IO uint32_t CR2;		/*!< I2C Control register 2				  Address Offset = 0x04 */
	__IO uint32_t OAR1;		/*!< I2C Own Address register 1 		  Address Offset = 0x08 */
	__IO uint32_t OAR2;		/*!< I2C Own Address register 2			  Address Offset = 0x0C */
	__IO uint32_t DR;		/*!< I2C Data register 				 	  Address Offset = 0x10 */
	__IO uint32_t SR1;		/*!< I2C Status register 1 				  Address Offset = 0x14 */
	__IO uint32_t SR2;		/*!< I2C Status register 2				  Address Offset = 0x18 */
	__IO uint32_t CCR;		/*!< I2C Clock Control register 		  Address Offset = 0x1C */
	__IO uint32_t TRISE;	/*!< I2C TRISE register 				  Address Offset = 0x20 */
	__IO uint32_t FLTR;		/*!< I2C FLTR register 					  Address Offset = 0x24 */

}I2C_TypeDef_t;

typedef struct{

	__IO uint32_t CR1;		 /*!< SPI Control Register 1 			      Address Offset = 0x00 */
	__IO uint32_t CR2;		 /*!< SPI Control Register 2 			   	  Address Offset = 0x04 */
	__IO uint32_t SR;		 /*!< SPI Status Register 					  Address Offset = 0x08 */
	__IO uint32_t DR;		 /*!< SPI Data Register 					  Address Offset = 0x0C */
	__IO uint32_t CRCPR;	 /*!< SPI CRC Polynomial Register 			  Address Offset = 0x10 */
	__IO uint32_t RXCRCR;	 /*!< SPI RX CRC Register 					  Address Offset = 0x14 */
	__IO uint32_t TXCRCR;	 /*!< SPI TX CRC Register 					  Address Offset = 0x18 */
	__IO uint32_t I2SCFGR;	 /*!< SPI_I2S Configuration Register 		  Address Offset = 0x1C */
	__IO uint32_t I2SPR;	 /*!< SPI_I2S Prescaler Register			  Address Offset = 0x20 */

}SPI_TypeDef_t;

typedef struct{

		__IO uint32_t SR;		/*!< USART Status Register  			      Address Offset = 0x00 */
		__IO uint32_t DR;		/*!< USART Data Register  			          Address Offset = 0x04 */
		__IO uint32_t BRR;		/*!< USART Baud Rate Register  			      Address Offset = 0x08 */
		__IO uint32_t CR1;		/*!< USART Control Register 1  			      Address Offset = 0x0C */
		__IO uint32_t CR2;		/*!< USART Control Register 2			      Address Offset = 0x10 */
		__IO uint32_t CR3;		/*!< USART Control Register 3 			      Address Offset = 0x14 */
		__IO uint32_t GTPR;		/*!< USART GTPR Register  			          Address Offset = 0x18 */

}USART_TypeDef_t;

#define GPIOA		( (GPIO_TypeDef_t *)(GPIOA_BASE_ADDR)    )
#define GPIOB		( (GPIO_TypeDef_t *)(GPIOB_BASE_ADDR)    )
#define GPIOC		( (GPIO_TypeDef_t *)(GPIOC_BASE_ADDR)    )
#define GPIOD		( (GPIO_TypeDef_t *)(GPIOD_BASE_ADDR)    )
#define GPIOE		( (GPIO_TypeDef_t *)(GPIOE_BASE_ADDR)    )
#define GPIOF		( (GPIO_TypeDef_t *)(GPIOF_BASE_ADDR)    )
#define GPIOG		( (GPIO_TypeDef_t *)(GPIOG_BASE_ADDR)    )
#define GPIOH		( (GPIO_TypeDef_t *)(GPIOH_BASE_ADDR)    )

#define RCC			( (RCC_TypeDef_t *)(RCC_BASE_ADDR)       )

#define SYSCFG 		( (SYSCFG_TypeDef_t *)(SYSCFG_BASE_ADDR) )

#define EXTI        ( (EXTI_TypeDef_t *)(EXTI_BASE_ADDR)     )

#define SPI1 		( (SPI_TypeDef_t *)(SPI1_BASE_ADDR)      )
#define SPI2 		( (SPI_TypeDef_t *)(SPI2_BASE_ADDR)      )
#define SPI3 		( (SPI_TypeDef_t *)(SPI3_BASE_ADDR)      )
#define SPI4 		( (SPI_TypeDef_t *)(SPI4_BASE_ADDR)      )

#define USART2 		( (USART_TypeDef_t *)(USART2_BASE_ADDR)  )
#define USART3 		( (USART_TypeDef_t *)(USART3_BASE_ADDR)  )
#define UART4 		( (USART_TypeDef_t *)(UART4_BASE_ADDR)   )
#define UART5 		( (USART_TypeDef_t *)(UART5_BASE_ADDR)   )

#define USART1		( (USART_TypeDef_t *)(USART1_BASE_ADDR)  )
#define USART6		( (USART_TypeDef_t *)(USART6_BASE_ADDR)  )

#define I2C1		( (I2C_TypeDef_t *)(I2C1_BASE_ADDR)      )
#define I2C2		( (I2C_TypeDef_t *)(I2C2_BASE_ADDR)      )
#define I2C3		( (I2C_TypeDef_t *)(I2C3_BASE_ADDR)      )

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
#define RCC_AHB1ENR_GPIOFEN_Msk		(0x1UL << RCC_AHB1ENR_GPIOFEN_Pos)	/*!< 0x00000020										*/
#define RCC_AHB1ENR_GPIOFEN			RCC_AHB1ENR_GPIOFEN_Msk				/*!< RCC AHB1ENR Register GPIOFEN Register  Macro       */
#define RCC_AHB1ENR_GPIOGEN_Pos		(6U)								/*!< RCC AHB1ENR Register GPIOGEN Register Bit Position */
#define RCC_AHB1ENR_GPIOGEN_Msk		(0x1UL << RCC_AHB1ENR_GPIOGEN_Pos)	/*!< 0x00000040										*/
#define RCC_AHB1ENR_GPIOGEN			RCC_AHB1ENR_GPIOGEN_Msk				/*!< RCC AHB1ENR Register GPIOGEN Register  Macro       */
#define RCC_AHB1ENR_GPIOHEN_Pos		(7U)								/*!< RCC AHB1ENR Register GPIOHEN Register Bit Position */
#define RCC_AHB1ENR_GPIOHEN_Msk		(0x1UL << RCC_AHB1ENR_GPIOHEN_Pos)	/*!< 0x00000080										*/
#define RCC_AHB1ENR_GPIOHEN			RCC_AHB1ENR_GPIOHEN_Msk				/*!< RCC AHB1ENR Register GPIOHEN Register  Macro       */

#define RCC_APB2ENR_SYSCFG_Pos		(14U)								/*!< RCC APB2ENR Register SYSCFG Register Bit Position  */
#define RCC_APB2ENR_SYSCFG_Msk		(0x1UL << RCC_APB2ENR_SYSCFG_Pos)	/*!< 0x00004000										*/
#define RCC_APB2ENR_SYSCFG			RCC_APB2ENR_SYSCFG_Msk				/*!< RCC APB2ENR Register SYSCFG Register  Macro        */

#define RCC_APB2ENR_SPI1_Pos		(12U)								/*!< RCC APB2ENR Register SPI1 Register Bit Position    */
#define RCC_APB2ENR_SPI1_Msk		(0x1UL << RCC_APB2ENR_SPI1_Pos)		/*!< 0x00001000										    */
#define RCC_APB2ENR_SPI1			RCC_APB2ENR_SPI1_Msk				/*!< RCC APBENR  Register SPI1 Register Macro 		    */
#define RCC_APB1ENR_SPI2_Pos		(14U)								/*!< RCC APB1ENR Register SPI2 Register Bit Position    */
#define RCC_APB1ENR_SPI2_Msk		(0x1UL << RCC_APB1ENR_SPI2_Pos)		/*!< 0x00004000										    */
#define RCC_APB1ENR_SPI2			RCC_APB1ENR_SPI2_Msk				/*!< RCC APB1ENR Register SPI2 Register Macro 		    */
#define RCC_APB1ENR_SPI3_Pos		(15U)								/*!< RCC APB1ENR Register SPI3 Register Bit Position    */
#define RCC_APB1ENR_SPI3_Msk		(0x1UL << RCC_APB1ENR_SPI3_Pos)		/*!< 0x00008000										    */
#define RCC_APB1ENR_SPI3			RCC_APB1ENR_SPI3_Msk				/*!< RCC APB1ENR Register SPI3 Register Macro 		    */
#define RCC_APB2ENR_SPI4_Pos		(13U)								/*!< RCC APB2ENR Register SPI4 Register Bit Position    */
#define RCC_APB2ENR_SPI4_Msk		(0x1UL << RCC_APB2ENR_SPI4_Pos)		/*!< 0x00002000										    */
#define RCC_APB2ENR_SPI4			RCC_APB2ENR_SPI4_Msk				/*!< RCC APBENR  Register SPI4 Register Macro 		    */

#define RCC_APB1ENR_USART2_Pos		(17U)								/*!< RCC APB1ENR Register USART2 Register Bit Position  */
#define RCC_APB1ENR_USART2_Msk		(0x1UL << RCC_APB1ENR_USART2_Pos)	/*!< 0x00020000 										*/
#define RCC_APB1ENR_USART2			RCC_APB1ENR_USART2_Msk				/*!< RCC APBENR  Register USART2 Register Macro 	    */

#define RCC_APB1ENR_I2C1_Pos		(21U)  								/*!< RCC APB1ENR Register I2C1   Register Bit Position  */
#define RCC_APB1ENR_I2C1_Msk		(0x1UL << RCC_APB1ENR_I2C1_Pos)		/*!< 0x00200000 										*/
#define RCC_APB1ENR_I2C1			RCC_APB1ENR_I2C1_Msk				/*!< RCC APBENR  Register I2C1   Register Macro 	    */

#define SPI_CR1_SPE					(6U)
#define SPI_CR1_DFF					(11U)

#define SPI_CR2_RXIE				(6U)
#define SPI_CR2_TXIE				(7U)

#define SPI_SR_RXNE					(0U)
#define SPI_SR_TXE					(1U)
#define SPI_SR_BSY					(7U)

#define USART_CR1_UE				(13U)
#define USART_CR1_TxEIE				(7U)
#define USART_CR1_RxEIE				(5U)

#define USART_CR2_STOPBIT			(12U)

#define USART_SR_TXE				(7U)
#define USART_SR_TC					(6U)
#define USART_SR_RxNE				(5U)

#define I2C_CR1_PE					(0U)




#define SPI_FLAG_TXE				(1U << SPI_SR_TXE )
#define SPI_FLAG_BSY				(1U << SPI_SR_BSY )
#define SPI_FLAG_RXNE				(1U << SPI_SR_RXNE)

#define USART_FLAG_TXE				(1U << USART_SR_TXE)
#define USART_FLAG_TC				(1U << USART_SR_TC )
#define USART_FLAG_RxNE				(1U << USART_SR_RxNE)

#define USART_ENABLE				(1U << USART_CR1_UE)

#include "my_RCC.h"
#include "my_EXTI.h"
#include "my_SPI.h"
#include "my_GPIO.h"
#include "my_USART.h"
#include "my_I2C.h"

#endif /* MY_STM32F446XX_H_ */
