bits 32

MB_ALIGN           equ 1<<0
MB_MEMINFO         equ 1<<1
MB_FLAGS           equ MB_ALIGN | MB_MEMINFO
MB_MAGIC           equ 0x1BADB002
MB_CHECKSUM        equ -(MB_MAGIC + MB_FLAGS)

section .boot
    align   4
    dd      MB_MAGIC      ; Magic Value for Multiboot
    dd      MB_FLAGS      ; Flags for Multiboot
    dd      MB_CHECKSUM   ; Checksum of Magic and Flags - ( Magic + Flags )

section .bss
    align   16
stack_bottom: ; ESP Definition
    resb    16384
stack_top:

section .text
    extern    _k_main       ; Kernel Main (from C)
    extern    _k_initialize ; Initialize Kernel (from C)
    global    _start        ; Global Assembly Entry

_start:
    mov     esp, stack_top
        
    ; Switch to Protected Mode
    mov     eax, cr0
    or      eax, 1
    mov     cr0, eax

    jmp     _kstart

_kstart:
    call    _k_initialize ; Initialize Kernel
    call    _k_main       ; Call kernel Main

.loop:	hlt
	jmp .loop
.end:
