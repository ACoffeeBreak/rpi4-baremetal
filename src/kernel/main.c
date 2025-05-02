// Standart Libraries
#include <stdint.h>
#include <stdio.h>
// User-defined Libraries
#include "uart.h"
#include "gpio.h"
#include "system_timer.h"
#include "arm_timer.h"

int main() {
    // Some functions in BETA
    uart_init();
    sends_uart("This is Hello World!\nPlease enter the password.\n");
    receives_uart();
    uart_close();
    see_time();
    delay(1000000);
    delay_arm_timer(3);
    sends_gpio("password");

    while(1);
}
