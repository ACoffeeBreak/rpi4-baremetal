#ifndef ARM_TIMER_H
#define ARM_TIMER_H

#include <stdint.h> 

void arm_timer_enable(void);
void arm_timer_wait(void);

void delay_arm_timer(uint32_t seconds);

#endif