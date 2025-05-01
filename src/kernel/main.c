#include <stdint.h>
#include <stdio.h>

#include "uart.h"
#include "gpio.h"
#include "system_timer.h"
#include "arm_timer.h"

int main() {
    // İsteğe bağlı çalıştırma kodları
    uart_init();
    // İsteğe bağlı çalıştırma kodları
    sends_uart("This is Hello World!\nPlease enter the password.\n");
    receives_uart();
    uart_close();
    see_time();
    delay(1000000);
    see_time();
    delay_arm_timer(3);
    
    sends_gpio("password");

    while(1);
}

/* Ana fonksiyonun dönüş tipi ve dönüş sonucunda Assemby geçişi hazırlanmalı.
*/