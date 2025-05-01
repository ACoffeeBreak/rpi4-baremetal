.section ".text"

.global read_timer

.equ TIMER_BASE, 0xFE003000
.equ TIMER_CLO, 0x04   ; Lower 32 bit Counter Offset
.equ TIMER_CHI, 0x08   ; Upper 32 bit Counter Offset

read_timer:
    ldr x0, =TIMER_BASE
    ldr w1, [x0, #TIMER_CLO]
    ldr w2, [x0, #TIMER_CHI]
ret
