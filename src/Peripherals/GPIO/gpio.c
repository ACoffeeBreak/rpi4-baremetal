#include "gpio.h"

extern void gpio_enable(void);
extern void gpio_set(char c);
extern char gpio_get(void);
extern void gpio_disable(void);

void sends_gpio(char c) {
    gpio_set(c);
}

void receives_gpio() {
    // Just gpio gets? void -> char for function, for systems.
    char c = gpio_get();
    sends_gpio(c);
}