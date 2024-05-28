#include<stm32f411xe.h>
int main(void)
{
	/*Enable Reset Clock Control GPIOA and GPIOC*/
	RCC->AHB1ENR|=(1U<<0);
	RCC->AHB1ENR|=(1U<<2);
	/*Configure PA5 as Output function*/
	GPIOA->MODER|=(1U<<10);
	GPIOA->MODER&=~(1U<<11);
	/*Configure PC13 as Input function*/
	GPIOA->MODER&=~(1U<<26);
	GPIOA->MODER&=~(1U<<27);
	while(1)
	{
		if(GPIOC->IDR &(1U<<13))
		{
			GPIOA->ODR|=(1U<<5);
			for(int i=0;i<100000;i++);
		}
		GPIOA->ODR&=~(1U<<5);
	}
}
