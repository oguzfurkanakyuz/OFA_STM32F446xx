#include "stm32f446x.h"
#include "gpio.h"
#include <stdint.h>


static void GPIO_Config();


int main(void)
{
    /* Loop forever */
	GPIO_Config();

	while(1){
		GPIO_Write_Pin(GPIOA, GPIO_PIN_5, GPIO_Pin_Set);
	}
}

static void GPIO_Config(){

	RCC_GPIOA_CLK_ENABLE();


	GPIO_InitTypeDef_t GPIO_InitStructure = { 0 };
	GPIO_InitStructure.pin_Number = GPIO_PIN_5;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT;
	GPIO_InitStructure.Otype = GPIO_OTYPE_PP;
	GPIO_InitStructure.PuPd = GPIO_PUPD_NOPULL;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}
