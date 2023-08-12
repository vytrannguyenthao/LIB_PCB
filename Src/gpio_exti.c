#include "gpio_exti.h"

void PA1_exti_init(void){
	/***********************Steps followed***********************
	 * 0. Configure GPIO pin to input Pull-up/ Pull-down mode.
	 * 1. Enable the AFIO bit in the RCC_APB2ENR Register.
	 * 2. Configure the EXTI configuration Register in the AFIO_EXTICRx.
	 * 3. Disable the EXTI Mask EXTI_IMR register.
	 * 4. Configure the Trigger Selection bits in EXTI_RTSR and EXTI_FTSR.
	 * 5. Set the Interrupt Priority.
	 * 6. Enable EXTI in NVIC.
	 ***********************************************************/

	/*0.Configure GPIO pin to Pull-up input mode*/
	/*Enable clock to access GPIOA*/
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

	/*Set PA1 to input mode*/
	GPIOA->CRL &= ~(GPIO_CRL_MODE1_0 | GPIO_CRL_MODE1_1);

	/*Set PA1 to input Pull-up/ Pull-down mode (10)*/
	GPIOA->CRL |= GPIO_CRL_CNF1_1;
	GPIOA->CRL &= ~GPIO_CRL_CNF1_0;

	/*Configure the ODR (1-> Pull UP, 0-> Pull down)*/
	GPIOA->ODR |= GPIO_ODR_ODR1;

	/*1.Enable the AFIO bit in the RCC_APB2ENR Register*/
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;

	/*2.Configure the EXTI configuration Register in the AFIO_EXTICRx*/
	AFIO->EXTICR[0] &= ~(0xf<<4);		//PA1

	/*3.Disable the EXTI Mask in EXTI_IMR register*/
	EXTI->IMR |= EXTI_IMR_IM1;

	/*4.Configure the Trigger Selection bits in EXTI_RTSR and EXTI_FTSR*/
	/*Enable Rising Edge Trigger for PA1*/
	EXTI->RTSR |= EXTI_RTSR_RT1;

	/*Disable Falling Edge Trigger for PA1*/
	EXTI->FTSR &= ~EXTI_FTSR_FT1;

	/*5.Set the Interrupt Priority*/
	NVIC_SetPriority(EXTI1_IRQn, 1);

	/*6.Enable EXTI in NVIC*/
	NVIC_EnableIRQ(EXTI1_IRQn);
}
