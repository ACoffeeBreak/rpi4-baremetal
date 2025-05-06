.section ".text.boot"

.global _start
_start:

/* === _BEGIN_ === CORE MANAGE ========== [T-SERVICE] */
    mrs x0, mpidr_el1
    and x0, x0, #3
    cbz x0, core_start

halt_cpu:
    wfi
    b halt_cpu

core_start:
/* === _END_ === CORE MANAGE */

/* === _BEGIN_ === CLEAN AGENT ========== [T-SERVICE] */
    ldr x1, =0x801000
    mov sp, x1

    ldr x2, =__bss_start
    ldr x3, =__bss_size

    cbz x3, start_main
    udiv x3, x3, #8
    mul x4, x3, #8
    sub x5, __bss_size, x4

clear_bss:
    cbz x3, check_remainder
    str xzr, [x2], #8
    sub x3, x3, #1
    cbnz x3 clear_bss

check_remainder:
    cbz x5, start_main
    str xzr, [x2], #1
    cbnz x5, check_remainder
/* === _END_ === CLEAN AGENT */

/* === _BEGIN_ === SYSTEM LAUNCH ========== [SERVICE] */
start_main:
    bl main
    b halt_cpu
/* _END_ === SYSTEM LAUNCH */
