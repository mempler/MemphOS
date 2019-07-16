bits    32

MBALIGN         equ 1<<0
MEMINFO         equ 1<<1
FLAGS           equ MBALIGN | MEMINFO
MAGIC           equ 0x1BADB002
CHECKSUM        equ -(MAGIC + FLAGS)

section         .boot
        align   4
        dd      MAGIC ; Magic Value for a "Boot Loader"
        dd      FLAGS
        dd      CHECKSUM

section         .bss
        align 16
stack_bottom:
        resb 16384
stack_top:
 

section         .text
        extern kmain ; Kernel Main (from C)
        global _start ; Global Assembly Entry

_start:
        mov esp, stack_top

        call kmain ; Call kernel Main
	cli
.hang:	hlt
	jmp .hang
.end:
