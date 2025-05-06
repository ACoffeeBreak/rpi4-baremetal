### File Header 
Compatible with Doxygen.
```C
//==============================================================================
// Project: Raspberry Pi 4-B Bare Metal (rpi4-baremetal)
// @file: main.c
// Language: C
// @version: 0.1.1
// @update: 05.05.2025
// @author: ACoffeeBreak
// Contributors: See CONTRIBUTORS.md for a full list.
// @brief: Main application file for system startup.
//==============================================================================
```
### Libraries, Macros and Definitions
```C
// Standard Library
#include <stdint.h>
#include <stdio.h>

// Core System Dependencies
#include "system_timer.h"
#include "arm_timer.h"
#include "interrupt_manager.h"

// Hardware Abstraction Layer
#include "gpio.h"
#include "uart.h"
#include "i2c.h"

// Macros and Constants
#define RECOVER_BASE 1000
#define ERROR_COUNT 0
```
// ---------------------------------------------------------------------

### Then any service:
```C++
// _starts_ === SERVICE (CORE MANAGE) ================================== //
// This part of code does not anything, just executes a loop.
for(int i = 0;i != 100;i++) {
printf(i);
}
// See the SERVICES.md file to understand relationships between services.
// _ends_ === SERVICE (CORE MANAGE) ==================================== //
```
### Classic comments
```C++
int main() {
    // Just code examples
    Message this_message = uart_send("This is an alert message. Code: 5732993''int''8","dont optimize","send now");
    if (!this_message[1]) {
    continue;
}
    else {
    std::cout << Message::Full Message << Message::Date;
}
    while(1);
}
```
