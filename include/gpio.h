#ifndef GPIO_H
#define GPIO_H

void gpio_enable(void);
void gpio_set(char c);
char gpio_get(void);
void gpio_disable(void);

void sends_gpio(char c);
void receives_gpio(void);
/* Returns something needed.
For now, just writing to UART.
*/

#endif