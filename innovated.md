# Project: Register Lifecycle Analyzer for ARM Assembly

A lightweight analysis tool designed to trace and document the lifecycle of CPU registers across custom ARM assembly functions.  
It reads source code character-by-character, identifies usage patterns of registers like `x19`, and maps their active ranges
between functions (e.g., `enable_mini_uart` to `disable_mini_uart`).

Ideal for low-level debugging, bootloader development, and memory optimization on bare-metal systems such as the Raspberry Pi 4.

This tool transforms raw assembly code into structured, traceable behavior with human-readable logs and extensible logic hooks for
future integration with interrupt-based runtime monitoring.

### Sample usage in the terminal:

```
watch "code_file"
range "enable_mini_uart" to "disable_mini_uart"
get register table
get register life_cycle of x19: 0x00000000 to 0x00000000
```

### And sample output:

```
Watching "code_file"
In Range: enable_mini_uart -> disable_mini_uart

Register Table:
[w10, x19]

Life Cycle of x19 {
0x00000000 ->
[ACTIVATED IN enable_mini_uart]
enable_mini_uart {
ldr AUX_BASE ; 0x7E215000
}

-> AUX_BASE ; 0x7E215000
}

! Warning: x19 is not reset or released !
```


> This tool enables analysis of register usage across specific code regions.  
> > At the assembly level, a single register access can be costly—especially when memory is involved.  
> Understanding these traces helps us write more efficient and predictable low-level routines.
