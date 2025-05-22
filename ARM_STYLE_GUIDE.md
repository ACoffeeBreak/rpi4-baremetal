# Assembly Style Guide for rpi4-bare_metal

**Version**:        1.0.0
**Last Updated**:   22.05.2025

Every files starts with this header form:

```asm
/*=============================================================================
  Project:  rpi4-bare_metal
  File:     example.S
  Language: ARMv8-A Assembly
  Version:  a.bc.def
  Update:   dd.mm.yyyy

  Brief:    An example description
  ============================================================================*/
```

And continuous with these headers:

1. SECTIONS
```asm
.section ".text"
```

2. FUNCTIONS
```asm
.global enable_service
.global disable_service
```

3. MEMORY ADDRESSES
```asm
.equ ENABLES 0x0000000A   @ Enables the service 
.equ DISABLES 0x0000000F  @ Disables the service
```

An example code is like that:

```asm
/*=============================================================================
  Project:  rpi4-bare_metal
  File:     set_driver_as.s
  Language: ARMv8-A Assembly
  Version:  1.1.12
  Update:   22.05.2025

  Brief:    Sets the driver as main or queue.
  ============================================================================*/

.section ".text"

.global set_driver_as_main
.global set_driver_as_queue

.equ SET_AS_MAIN 0x39    @ Sets the driver as main
.equ SET_AS_QUEUE 0x42   @ Sets the driver as queue
```
