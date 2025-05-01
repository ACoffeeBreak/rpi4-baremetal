.section ".text"

; Functions
.global gpio_enable
.global gpio_set
.global gpio_get
.global gpio_disable

; On BETA
.global use_uart
.global select_gpio_pin

; GPIO Memory Adresses
.equ GPIO_BASE, 0x7E200000

; Using PIN
.equ GPIO_PIN, 17

; Read PIN Status
.equ GPLEV0, 0x34
.equ GPLEV1, 0x38

; Set LOW
.equ GPCLR0, 0x28
.equ GPCLR1, 0x2c

; Set HIGH
.equ GPSET0, 0x1c
.equ GPSET1, 0x20

; Select PIN
.equ GPFSEL0, 0x00
.equ GPFSEL1, 0x04
.equ GPFSEL2, 0x08
.equ GPFSEL3, 0x0c
.equ GPFSEL4, 0x10
.equ GPFSEL5, 0x14

; Less Memory Access
.global gpio_base_r
.global gpio_pin_r

select_gpio_pin:
    mov w10, w0
    
ret

gpio_enable:
    ldr x9, =GPIO_BASE

    ldr x1, [x9, #GPFSEL1]
    bic x1, x1, #(0b111 << ((GPIO_PIN % 10) * 3))
    orr x1, x1, #(0b001 << ((GPIO_PIN % 10) * 3))
    str x1, [x9, #GPFSEL1]
ret

gpio_set:

    ; C sends w0 value..
    cmp w0, #0
    bne set_high:

set_low:
    mov x2, #(1 << GPIO_PIN)
    str x2, [x9, #GPCLR0]
b end

set_high:
    mov x2, #(1 << GPIO_PIN)
    str x2, [x9, #GPSET0]

end:
ret

gpio_get:
    ldr w2, [x9, #GPLEV0]
    and w0, w2, #(1 << GPIO_PIN)
    lsr w0, w0, GPIO_PIN
ret

gpio_disable:
    ldr x1, [gpio_base_r, #GPFSEL1]
    bic x1, x1, #(0b111 << ((GPIO_PIN % 10) * 3))
    str x1, [gpio_base_r, #GPFSEL1]

    mov x1, #0
    str x1, [gpio_pin_r]
    str x1, [gpio_base_r]
    ret

use_uart: ; BETAAAAA
    ldr x1, [x9, #GPFSEL1]
    bic x1, x1, #(0b100 << ((GPIO_PIN % 10) * 3))
    orr x1, x1, #(0b100 << ((GPIO_PIN % 10) * 3))
    str x1, [x9, #GPFSEL1]
ret
