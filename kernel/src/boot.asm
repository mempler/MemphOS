bits    32

section         .text
        align   4
        dd      0x1BADB002 ; Magic Value for a "Boot Loader"
        dd      0x00
        dd      - (0x1BADB002+0x00)

global start ; Global Assembly Entry
extern kmain ; Kernel Main (from C)

start:
        call kmain ; Call kernel Main
        hlt ; do NOT exit
