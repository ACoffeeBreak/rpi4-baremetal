# This is the BETA header of every code files.
//==============================================================================
// @project: Raspberry Pi 4-B Bare Metal (rpi4-baremetal)
// @file: main.c
// @language: C
// @version: 0.1.1
// @last Update: 05.05.2025
// @authors: ACoffeeBreak
// @contributors: See CONTRIBUTORS.md for a full list.
// @description: Main application file for system startup.
//==============================================================================

# Service Token Comments, in BETA. Avoid using them for headers and macros. This is just a test.
// _starts_ === STANDART LIBRARY HEADERS ========================== //
#include <stdint.h>
#include <stdio.h>
// _ends_ === STANDART LIBRARY HEADERS ============================ //

// _starts_ === PROJECT CONFIGURATION / CONSTANTS ================= //
// _ends_ === PROJECT CONFIGURATION / CONSTANTS =================== //

// _starts_ === CORE SYSTEM DEPENDENCIES ========================== //
#include "system_timer.h"
#include "arm_timer.h"
// _ends_ === CORE SYSTEM DEPENDENCIES ============================ //

// _starts_ === HARDWARE ABSTRACTION LAYER ======================== //
#include "uart.h"
#include "gpio.h"
// _ends_ === HARDWARE ABSTRACTION LAYER ========================== //

// _starts_ === MACROS & CONSTANT DEFINITIONS ===================== //
#define BOOT_DELAY 1000000
#define PASSWORD_EXPECTED "rpi4baremetal"
// _ends_ === MACROS & CONSTANT DEFINITIONS ======================= //

// _starts === TYPE DEFINITIONS (STRUCTS / ENUMS) ================= //
// _ends === TYPE DEFINITIONS (STRUCTS / ENUMS) =================== //    

// _starts_ === STATIC FUNCTION DECLARATIONS ====================== //
// _ends_ === STATIC FUNCTION DECLARATIONS ======================== //

// _starts_ === GLOBAL VARIABLES ================================== //
// _ends_ === GLOBAL VARIABLES ==================================== //

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

// ---------------------------------------------------------------------
// What a beatiful header style
// ---------------------------------------------------------------------

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

// ---------------------------------------------------------------------

Then any service:

// _starts_ === SERVICE (CORE MANAGE) ================================== //
// This part of code does not anything, just executes a loop.
for(int i = 0;i != 100;i++) {
printf(i);
}
// See the SERVICES.md file to understand relationships between services.
// _ends_ === SERVICE (CORE MANAGE) ==================================== //
