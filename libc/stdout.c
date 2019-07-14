#include "stdout.h"
#include <drivers/terminal.h>

void _K_T_set_char(i8 pC, i32 pColF, i32 pColB, i32 pX, i32 pY);
void _K_T_print(CPChar pStr, i32 pColF, i32 pColB);
void _K_T_clear();

void
print(CPChar pStr) {
    _K_T_print(pStr, CCOL_LIGHT_GRAY, 0x00);
}

void
clear() {
    _K_T_clear();
}

void
print_colorized(CPChar pStr, i32 pColF, i32 pColB) {
    _K_T_print(pStr, pColF, pColB);
}
