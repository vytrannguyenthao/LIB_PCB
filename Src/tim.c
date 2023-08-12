#include "tim.h"

void Timer4ConfigPWMDMA(void){
	/***********************Steps followed***********************
	* 1. Enable Timer clock.
	* 2. Set the prescaler, the ARR and reset the timer count.
	* 3. Select PWR mode by setting OCxM bit in TIMx_CCMRx.
	* 4. Configure DMA Interrupt Enable Register in TIMx_DIER.
	* 5. Enable channels by setting CCxE bit in TIMx_CCER.
	* 6. Initialize all the registers by setting the UG bit in the TIMx_EGR register.
	* 7. Enable the Timer, and wait for the update Flag to set.
	 ***********************************************************/

	/*1.Enable Timer 4 clock*/
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;

	/*2.Set the prescaler, the ARR and reset the timer count*/
	/*Set TIM prescaler*/
	TIM4->PSC = 72-1;	//Each count by the counter take 1 microseccond

	/*Set TIM Auto-reload value*/
	TIM4->ARR = 1000-1;		// 100Hz

	/*Reset TIM_CNT*/
	TIM4->CNT = 0;

	/*3.Select PWR mode 1 (110) for channel 1,2*/
	/*Channel 1*/
	TIM4->CCMR1 &= ~TIM_CCMR1_OC1M_0;
	TIM4->CCMR1 |= TIM_CCMR1_OC1M_1;
	TIM4->CCMR1 |= TIM_CCMR1_OC1M_2;

	/*Channel 2*/
	TIM4->CCMR1 &= ~TIM_CCMR1_OC2M_0;
	TIM4->CCMR1 |= TIM_CCMR1_OC2M_1;
	TIM4->CCMR1 |= TIM_CCMR1_OC2M_2;

	/*4.Configure DMA Interrupt Enable Register in TIMx_DIER*/
	TIM4->DIER |= TIM_DIER_UDE | TIM_DIER_CC1DE | TIM_DIER_CC2DE;

	/*5.Enable channels by setting CCxE bit in TIMx_CCER*/
	/*Enable channel 1*/
	TIM4->CCER |= TIM_CCER_CC1E;

	/*Enable channel 2*/
	TIM4->CCER |= TIM_CCER_CC2E;

	/*6.Initialize all the registers by setting the UG bit in the TIMx_EGR register*/
	TIM4->EGR |= TIM_EGR_UG;

	/*7.Enable the Timer, and wait for the update Flag to set*/
	/*Enable timer*/
	TIM4->CR1 |= TIM_CR1_CEN;

	/*Wait for the update flag to set*/
	while(!(TIM4->SR & TIM_SR_UIF));
}

void Timer4ConfigPWM(void){
	/***********************Steps followed***********************
	* 1. Enable Timer clock.
	* 2. Set the prescaler, the ARR and reset the timer count.
	* 3. Select PWR mode by setting OCxM bit in TIMx_CCMRx.
	* 4. Enable channels by setting CCxE bit in TIMx_CCER.
	* 5. Initialize all the registers by setting the UG bit in the TIMx_EGR register.
	* 6. Enable the Timer, and wait for the update Flag to set.
	 ***********************************************************/

	/*1.Enable Timer 4 clock*/
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;

	/*2.Set the prescaler, the ARR and reset the timer count*/
	/*Set TIM prescaler*/
	TIM4->PSC = 0;

	/*Set TIM Auto-reload value*/
	TIM4->ARR = 7200-1;		// 1000Hz

	/*Reset TIM_CNT*/
	TIM4->CNT = 0;

	/*3.Select PWR mode 1 (110) for channel 1,2*/
	/*Channel 1*/
	TIM4->CCMR1 &= ~TIM_CCMR1_OC1M_0;
	TIM4->CCMR1 |= TIM_CCMR1_OC1M_1;
	TIM4->CCMR1 |= TIM_CCMR1_OC1M_2;

	/*Channel 2*/
	TIM4->CCMR1 &= ~TIM_CCMR1_OC2M_0;
	TIM4->CCMR1 |= TIM_CCMR1_OC2M_1;
	TIM4->CCMR1 |= TIM_CCMR1_OC2M_2;

	/*4.Enable channels by setting CCxE bit in TIMx_CCER*/
	/*Enable channel 1*/
	TIM4->CCER |= TIM_CCER_CC1E;

	/*Enable channel 2*/
	TIM4->CCER |= TIM_CCER_CC2E;

	/*5.Initialize all the registers by setting the UG bit in the TIMx_EGR register*/
	TIM4->EGR |= TIM_EGR_UG;

	/*6.Enable the Timer, and wait for the update Flag to set*/
	/*Enable timer*/
	TIM4->CR1 |= TIM_CR1_CEN;

	/*Wait for the update flag to set*/
	while(!(TIM4->SR & TIM_SR_UIF));
}

void Timer4_pwm_set_dutycycle(uint8_t channel, uint16_t dutycycle){
	/*Select the channel*/
	switch(channel){
		case 1:
			/*Set the duty cycle in CCRx register*/
			TIM4->CCR1 = dutycycle;
			break;
		case 2:
			/*Set the duty cycle in CCRx register*/
			TIM4->CCR2 = dutycycle;
			break;
		case 3:
			/*Set the duty cycle in CCRx register*/
			TIM4->CCR3 = dutycycle;
			break;
		case 4:
			/*Set the duty cycle in CCRx register*/
			TIM4->CCR4 = dutycycle;
			break;
		default:
			break;
	}
}

/*Timer 3 is using to auto read data from adc*/
void Timer3Config(void){
	/***********************Steps followed***********************
	* 1. Enable Timer clock.
	* 2. Set the prescaler and the ARR.
	* 3. Enable the Timer, and wait for the update Flag to set.
	 ***********************************************************/

	/*1.Enable Timer 3 clock*/
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

	/*2.Set the prescaler and the ARR*/
	/*Set TIM prescaler*/
	TIM3->PSC = 72-1;	//Each count by the counter take 1 microseccond

	/*Set TIM Auto-reload value*/
	TIM3->ARR = 1000-1;		// 100Hz


	/*Wait for the update flag to set*/
	while(!(TIM3->SR & TIM_SR_UIF));
}

/*Timer 2 is using to calculate time*/
void Timer2Config(void){
	/***********************Steps followed***********************
	* 1. Enable Timer clock.
	* 2. Set the prescaler and the ARR.
	* 3. Enable the Timer, and wait for the update Flag to set.
	 ***********************************************************/

	/*1.Enable Timer 2 clock*/
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	/*2.Set the prescaler and the ARR*/
	/*Set TIM prescaler*/
	TIM2->PSC = 8-1;	//Each count by the counter take 1 microseccond

	/*Set TIM Auto-reload value*/
	TIM2->ARR = 0xffff-1;	//ARR resister is 16 bit resister

	/*3.Enable the Timer, and wait for the update Flag to set*/
	/*Enable timer*/
	TIM2->CR1 |= TIM_CR1_CEN;

	/*Wait for the update flag to set*/
	while(!(TIM2->SR & TIM_SR_UIF));
}

void Delay_us (uint16_t us){
	/***********************Steps followed***********************
	 * 1. RESET the Counter
	 * 2. Wait for the Counter to reach the entered value. As each count will take 1 us,
		 the total waiting time will be the required us delay
	 ***********************************************************/
	/*Reset counter*/
	TIM2->CNT = 0;

	/*Wait for the counter to reach the entered value*/
	while (TIM2->CNT < us);

}
void Delay_ms (uint16_t ms){
	for(uint16_t i = 0; i < ms; i++){
		Delay_us(1000);
	}
}
