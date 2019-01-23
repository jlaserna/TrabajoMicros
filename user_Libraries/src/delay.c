#include "stm32f4xx.h"
#include "delay.h"

volatile u32 Micros;
volatile u32 Millis;

void Systick_Configuration(void)
{  
	SystemInit();
	SystemCoreClockUpdate();
	
	if (SysTick_Config (SystemCoreClock / 1000))
		while (1); 

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	NVIC_SetPriority(SysTick_IRQn, 0);
	  
	Millis = 0;
}

u32 micros(void)
{
	Micros = Millis*1000 + 1000 - SysTick->VAL/systemFrequency;
	return Micros; 
}

u32 millis(void)
{
	return Millis;
}

void delay_ms(u32 nTime)
{
	u32 curTime = Millis;
	while((nTime-(Millis-curTime)) > 0);
}

void delay_us(u32 nTime)
{
	u32 curTime = micros();
	while((nTime-(micros()-curTime)) > 0);
}  

void elapseMicros(u32 targetTime, u32 oldt)
{
	while((micros()-oldt)<targetTime);
}


void elapseMillis(u32 targetTime, u32 oldt)
{
	while((millis()-oldt)<targetTime);
}

