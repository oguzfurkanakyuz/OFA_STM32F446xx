#include "my_stm32f446xx.h"
#include "my_GPIO.h"

static void GPIO_Config();
//static void GPIO_LockTest();
static void GPIO_ButtonConfig();
static void SPI_Config();
static void SPI_GPIO_Config();

SPI_HandleTypeDef_t SPI_Handle;

void EXTI0_IRQHandler(){

	char msgToSend[] = "Hello World!\n";

	if( EXTI->PR & 0x1){

		EXTI->PR |= (0x1U << 0);

		SPI_TransmitData_IT( &SPI_Handle, (uint8_t *)msgToSend, strlen(msgToSend) );
	}

}

void SPI1_IRQHandler(){

	SPI_InterruptHandler(&SPI_Handle);


}



int main(void)
{


	GPIO_Config();
	GPIO_ButtonConfig();

	SPI_Config();
	SPI_GPIO_Config();


	//GPIO_LockTest();
	//GPIO_LockPin(GPIOC,GPIO_PIN_13);

	while(1){

	}

}


static void GPIO_Config(){

	RCC_GPIOA_CLK_ENABLE();	 // GPIO A port clock enabled
	RCC_GPIOC_CLK_ENABLE();	 // GPIO C port clock enabled
	RCC_SYSCFG_CLK_ENABLE(); // SYSCFG clock enabled

	GPIO_InitTypeDef_t GPIO_InitStructure = { 0 };
	GPIO_InitStructure.pin_Number |= GPIO_PIN_6;
	GPIO_InitStructure.Mode |= GPIO_MODE_OUTPUT;
	GPIO_InitStructure.Otype |= GPIO_OTYPE_PP;
	GPIO_InitStructure.PuPd |= GPIO_PUPD_NOPULL;
	GPIO_InitStructure.Speed |= GPIO_SPEED_FREQ_HIGH;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	memset(&GPIO_InitStructure, 0, sizeof(GPIO_InitStructure) );

	GPIO_InitStructure.pin_Number |= GPIO_PIN_13;
	GPIO_InitStructure.Mode |= GPIO_MODE_INPUT;
	GPIO_InitStructure.PuPd |= GPIO_PUPD_PULLUP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	EXTI_LineConfig( EXTI_PortSource_GPIOC, EXTI_LineSource_7);

}

/*
static void GPIO_LockTest(){

	GPIO_InitTypeDef_t GPIO_InitStruct = {0};

	GPIO_InitStruct.pin_Number = GPIO_PIN_13;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT;
	GPIO_InitStruct.PuPd = GPIO_PUPD_NOPULL;
	GPIO_Init(GPIOC, &GPIO_InitStruct);

}
*/
static void GPIO_ButtonConfig(){


	EXTI_InitTypeDef_t EXTI_InitStruct = {0};

	EXTI_LineConfig(EXTI_PortSource_GPIOC, EXTI_LineSource_0);

	EXTI_InitStruct.LineCmd = ENABLE;
	EXTI_InitStruct.EXTI_LineNumber = EXTI_LineSource_0;
	EXTI_InitStruct.EXTI_Mode = EXTI_MODE_INTERRUPT;
	EXTI_InitStruct.EXTI_TriggerSelection = EXTI_TRIGGER_RISING;
	EXTI_Init(&EXTI_InitStruct);

	NVIC_EnableInterrupt(EXTI0_IRQNumber);

}

static void SPI_Config(){

	RCC_SPI1EN_CLK_ENABLE();
	SPI_Handle.Instance = SPI1;


	SPI_Handle.Init.BaudRate = SPI_BAUDRATE_DIV8;
	SPI_Handle.Init.BusConfig = SPI_FULL_DUBLEX;
	SPI_Handle.Init.CPHA = SPI_CPHA_FIRST;
	SPI_Handle.Init.CPOL = SPI_CPOL_LOW;
	SPI_Handle.Init.DFF_Format = SPI_DFF_8BITS;
	SPI_Handle.Init.FrameFormat = SPI_FRAMEFORMAT_MSB;
	SPI_Handle.Init.Mode = SPI_MASTER;
	SPI_Handle.Init.SSM_Cmd = SPI_SSM_ENABLE;

	SPI_Init(&SPI_Handle);

	NVIC_EnableInterrupt(SPI1_IRQNumber);
	SPI_PeriphCmd(&SPI_Handle, ENABLE);


}

static void SPI_GPIO_Config(){

	GPIO_InitTypeDef_t GPIO_InitStruct = { 0 };

	GPIO_InitStruct.pin_Number = GPIO_PIN_5 | GPIO_PIN_7;
	GPIO_InitStruct.Mode = GPIO_MODE_AF;
	GPIO_InitStruct.Otype = GPIO_OTYPE_PP;
	GPIO_InitStruct.PuPd = GPIO_PUPD_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF5;

	GPIO_Init(GPIOA, &GPIO_InitStruct);
}
