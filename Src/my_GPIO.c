/*
 * my_GPIO.c
 *
 *  Created on: 7 Tem 2021
 *      Author: furkan
 */

#include "my_GPIO.h"

/**
  * @brief  Initializes the GPIOx peripheral according to the specified parameters in the GPIO_Init.
  * @param  GPIOx where x can be (A..K) to select the GPIO peripheral for STM32F429X device or
  *                      x can be (A..I) to select the GPIO peripheral for STM32F40XX and STM32F427X devices.
  * @param  GPIO_Init pointer to a GPIO_InitTypeDef structure that contains
  *         the configuration information for the specified GPIO peripheral.
  * @retval None
  */

void GPIO_Init(GPIO_TypeDef_t *GPIOx, GPIO_InitTypeDef_t *GPIO_ConfigStruct){

	uint32_t fake_position = 0x00U;
	uint32_t last_position = 0x00U;
	uint32_t temp_value = 0x00U;

	for(uint32_t position = 0U; position < MAX_PIN_NUMBER; position++){

		fake_position = (0x1U << position);
		last_position = (uint32_t)(GPIO_ConfigStruct->pin_Number) & (fake_position);

		if(last_position == fake_position){

			/* Mode Register Configuration */
			temp_value = GPIOx->MODER;
			temp_value &= ~(0x3U << (position * 2U));
			temp_value |= (GPIO_ConfigStruct->Mode << (position * 2U));
			GPIOx->MODER = temp_value;

			if(GPIO_ConfigStruct->Mode == GPIO_MODE_OUTPUT || GPIO_ConfigStruct->Mode == GPIO_MODE_AF){

				/* Output Type Register Configuration*/
				temp_value = GPIOx->OTYPER;
				temp_value &= ~(0x1U << position);
				temp_value |= (GPIO_ConfigStruct->Otype << position);
				GPIOx->OTYPER = temp_value;

				/* Output Speed Register Configuration*/
				temp_value = GPIOx->OSPEEDR;
				temp_value &= ~(0x3U << (position * 2U));
				temp_value |= (GPIO_ConfigStruct->Speed << (position * 2U ));
				GPIOx->OSPEEDR = temp_value;


				if(GPIO_ConfigStruct->Mode == GPIO_MODE_AF ){

					temp_value = GPIOx->AFR[position >> 3U];
					temp_value &= ~(0xFU << ( (position & 0x7U) * 4) );
					temp_value |= (GPIO_ConfigStruct->Alternate << ( (position & 0x7U) * 4) );
					GPIOx->AFR[position >> 3U] = temp_value;

			}

			/* Pull-Up/Pull-Down Register Configuration*/
			temp_value = GPIOx->PUPDR;
			temp_value &= ~(0x3U << (position * 2U));
			temp_value |= (GPIO_ConfigStruct->PuPd << (position * 2U));
			GPIOx->PUPDR = temp_value;



			}

		}

	}

}


/**
  * @brief  Sets HIGH or LOW specified pin of port.
  *
  *
  * @param  GPIOx specifies the which port will be set.
  *
  * @param  pinNumber specifies the pin of the port. It can be changed between 0-15.
  *
  * @param  pinState specifies the desired pin situation.
  *            @arg GPIO_Pin_Reset: to clear the port pin.
  *            @arg GPIO_Pin_Set: to set the port pin.
  *
  * @retval None
  */
void GPIO_Write_Pin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber, GPIO_PinState_t pinState){

	if(pinState == GPIO_Pin_Set)
	{
		GPIOx->BSRR = pinNumber;
	}
	else
	{
		GPIOx->BSRR = (pinNumber << 16U);
	}
}

/**
  * @brief  Reads the specified pin of the port.
  *
  * @param  GPIOx specifies the which port will be set.
  *
  * @param  GPIO_Pin specifies the port bit to read.
  *         This parameter can be GPIO_PIN_x where x can be (0..15).
  *
  * @retval The input value of the pin.
  */
GPIO_PinState_t GPIO_Read_Pin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber){

	GPIO_PinState_t bit_status = GPIO_Pin_Reset;

	if((GPIOx->IDR & pinNumber) != GPIO_Pin_Reset){

		bit_status = GPIO_Pin_Set;
	}

	return bit_status;

}

/**
  * @brief  Toggles the specified GPIO pins.
  * @param  GPIOx Where x can be (A..K) to select the GPIO peripheral for STM32F429X device or
  *                      x can be (A..I) to select the GPIO peripheral for STM32F40XX and STM32F427X devices.
  * @param  GPIO_Pin Specifies the pins to be toggled.
  * @retval None
  */

void GPIO_TogglePin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber){

	uint32_t temp_odr;

	temp_odr = GPIOx->ODR;

	GPIOx->BSRR = ((temp_odr & pinNumber) << 16U) | (~temp_odr & pinNumber);

}

/**
  * @brief  Locks the specified pin of the port.
  *
  * @param  GPIOx specifies the which port will be set.
  *
  * @param  GPIO_Pin specifies the port bit to read.
  *         This parameter can be GPIO_PIN_x where x can be (0..15).
  *
  * @retval None
  */

void GPIO_LockPin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber){

	uint32_t temp_value = (0x1U << 16) | pinNumber;

	GPIOx->LCKR = temp_value;
	GPIOx->LCKR = pinNumber;
	GPIOx->LCKR = temp_value;
	temp_value  = GPIOx->LCKR;

}




