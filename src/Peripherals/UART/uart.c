#include "uart.h"

extern void uart_init(void);
extern void uart_disable(void);
extern void uart_putc(char c);
extern char uart_getc(void);

void sends_uart(const char *str) {
    // Now it is just for char arrays.
    if (!str) {
        // Return a meaningfull message.
        return;
    }
    while(*str) {
        uart_putc(*str++);
    }
}

void receives_uart() {
    // Just uart gets? void -> char for function, for systems.
    char uart_got_value = uart_getc();
    uart_putc(uart_got_value);
}