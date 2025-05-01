.section ".text"

; Functions
.global uart_init
.global uart_putc
.global uart_getc
.global uart_close

; UART Memory Adresses
.equ UART_BASE, 0xFE201000
.equ UART_CR, 0x30         ; Control Register
.equ UART_DR, 0x00         ; Data Register (Read/Write)
.equ UART_FR, 0x18         ; Flag Register
.equ UART_IBRD, 0x24       ; Integer Baud Rate Divisor
.equ UART_FBRD, 0x28       ; Fractional Baud Rate Divisor
.equ UART_LCRH, 0x2C       ; Line Control Register 
.equ UART_IMSC, 0x38       ; Interrupt Mask Set/Clear

uart_init:
    ldr x19, =UART_BASE

    ; Reset UART
    mov w10, #0
    str w10, [x19, UART_CR]

    ; Baud Rate for standart '115200' value
    mov w9, #26
    str w9, [x19, #UART_IBRD]
    mov w9, #3
    str w9, [x19, #UART_FBRD]

    ; Data format - 8 bits, 1 stop bit, FIFO active
    mov w10, #0x70
    str w10, [x19, #UART_LCRH]

    ; Disable UART Interrupts
    mov w9, #0
    str w9, [x19, #UART_IMSC]

    ; Enable UART
    mov w10, #0x301
    str w10, [x19, #UART_CR]
ret

uart_putc:
wait_on_tx:
    ldr x19, =UART_BASE

    ; Enable data transfer / Check suitability
    ldr w9, [x19, #UART_FR]
    tst w9, #0x20
    bne wait_on_tx

    ; Data-out
    str w0, [x19, #UART_DR]
ret

uart_getc:
wait_on_rx:
    ldr x19, =UART_BASE

    ; Enable data transfer / Check suitability
    ldr w9, [x19, #UART_FR]
    tst w9, #0x10
    bne wait_on_rx

    ; Data-in
    ldr w0, [x19, #UART_DR]
ret

uart_disable:
    ldr x19, =UART_BASE

    ; Disable UART
    mov w9, #0
    str w9, [x19, #UART_CR]
    str w9, [x19, #UART_IMSC]

ret

    ; Think about loading UART_BASE everytime.
    ; Think about use of register.
    