#include "arm_timer.h"

extern void arm_timer_enable(void);
extern void arm_timer_wait(void);

void delay_arm_timer(uint32_t seconds) {
    for (uint32_t i = 0;i < seconds;i++) {
        arm_timer_wait();
    }
}