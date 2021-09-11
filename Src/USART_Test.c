/*
 * USART_Test.c
 *
 *  Created on: 31 Ağu 2021
 *      Author: furkan
 */
#include "my_stm32f446xx.h"
USART_HandleTypedef_t USART_Handle;

static void UART_Config(void);
static void GPIO_Config();

void USART2_IRQHandler()
{
	USART_InterruptHandler(&USART_Handle);
}

int main(void){

	char msg[] = "Hello World\n";
	char rec_msg[50];

	UART_Config();
	GPIO_Config();

	//USART_TransmitData(&USART_Handle, (uint8_t*) msg, strlen(msg) );
	USART_TransmitData_IT(&USART_Handle, (uint8_t*) msg, strlen(msg));
	USART_ReceiveData_IT(&USART_Handle, (uint8_t*)rec_msg, 20);
	while(1);

	return 0;
}

static void UART_Config()
{
	RCC_USART2_CLK_ENABLE();
	USART_Handle.Instance = USART2;

	USART_Handle.Init.BaudRate = 115200;
	USART_Handle.Init.HardWareFlowControl = USART_HW_NONE;
	USART_Handle.Init.Mode = USART_MODE_TX;
	USART_Handle.Init.OverSampling = USART_OVERSAMPLING_16;
	USART_Handle.Init.Parity = USART_PARITY_NONE;
	USART_Handle.Init.StopBits = USART_STOPBITS_1;
	USART_Handle.Init.WordLength = USART_WORDLENGTH_8BIT;

	USART_Init(&USART_Handle);
	USART_PeriphCmd(&USART_Handle, ENABLE);

	NVIC_EnableInterrupt(USART2_IRQNumber);
}

static void GPIO_Config()
{

	GPIO_InitTypeDef_t GPIO_InitStructure = { 0 };

	RCC_GPIOA_CLK_ENABLE();

	GPIO_InitStructure.pin_Number = GPIO_PIN_2;
	GPIO_InitStructure.Mode = GPIO_MODE_AF;
	GPIO_InitStructure.Otype = GPIO_OTYPE_PP;
	GPIO_InitStructure.PuPd = GPIO_PUPD_NOPULL;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStructure.Alternate = GPIO_AF7;

	GPIO_Init(GPIOA,&GPIO_InitStructure);

}
