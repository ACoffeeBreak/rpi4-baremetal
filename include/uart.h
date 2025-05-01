#ifndef UART_H
#define UART_H

void uart_init(void);
void uart_disable(void);
void uart_putc(const char c);
// Look at for parameter '"constant" char c'
char uart_getc(void);

void sends_uart(char c);
void receives_uart(void);
/* Returns something needed.
For now, just writing to UART.
*/

#endif