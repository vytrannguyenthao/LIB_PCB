#ifndef __TIM_H__
#define	__TIM_H__

#include "stm32f1xx.h"

void Timer2Config(void);
void Timer3Config(void);
void Delay_us (uint16_t us);
void Delay_ms (uint16_t ms);
void Timer4ConfigPWM(void);
void Timer4ConfigPWMDMA(void);
void Timer4_pwm_set_dutycycle(uint8_t channel, uint16_t dutycycle);

#endif
