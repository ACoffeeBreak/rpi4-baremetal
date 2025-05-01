.section ".text"

.global arm_timer_enable
.global arm_timer_wait
.global arm_timer_handler
// Change

.equ ARM_TIMER_BASE, 0xFE00B000
.equ ARM_TIMER_LOAD, 0x00     ; Load time for countdown
.equ ARM_TIMER_VALUE, 0x04    ; Read time value
.equ ARM_TIMER_CTRL, 0x08     ; Control 
.equ ARM_TIMER_IRQ_CLR, 0x0C  ; Interrupt Clear
.equ ARM_TIMER_RAW_IRQ, 0x10  ; Check for Interrupt
.equ ARM_ENABLE_IRQS_1, 0x210
.equ ARM_IRQ_PENDING_1, 0x204
.equ IRQ_ARM_TIMER, (1 << 0)

// Less Memory Access
.global arm_timer_base_r

arm_timer_enable:
    ldr r1, =ARM_TIMER_BASE
    str r1, arm_timer_base_r

    mov r0, #1000000
    str r0, [arm_timer_base_r, #ARM_TIMER_LOAD]

    mov r0, #(1 << 7 | 1 << 5 | 1 << 1) ; Adjusts enable counter, 23-bit counter (timer) and prescale 1:256
    str r0, [arm_timer_base_r, #ARM_TIMER_CTRL]

    ldr r1, [arm_timer_base_r, #ARM_ENABLE_IRQS_1]
    mov r0, IRQ_ARM_TIMER
    str r0, [r1]

bx lr

arm_timer_wait:
    wait_loop:
    ldr r0, [arm_timer_base_r, #ARM_TIMER_VALUE]
    cmp r0, #0
    bne wait_loop

    str r0, [arm_timer_base_r, #ARM_TIMER_IRQ_CLR]

bx lr

arm_timer_handler:
    push {r0, r1}

    mov r0, #1
    str r0, [arm_timer_base_r, #ARM_TIMER_IRQ_CLR]
    
    pop {r0, r1}
subs pc, lr, #4
