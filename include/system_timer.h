#ifndef SYSTEM_TIMER_H
#define SYSTEM_TIMER_H

#include <stdint.h>

uint64_t read_timer();

void see_time();
/* Returns something needed.
For now, just writing to UART.
*/

#endif