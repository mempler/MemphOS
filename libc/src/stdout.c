#include "stdout.h"
#include <drivers/terminal.h>

void _K_T_set_char(i8 pC, i32 pColF, i32 pColB, i32 pX, i32 pY);
void _K_T_clear();

extern i32 _K_T_CPOS_X;
extern i32 _K_T_CPOS_Y;

void
print(CPChar pStr) {
    print_colorized(pStr, CCOL_LIGHT_GRAY, 0x00);
}

void
clear() {
    _K_T_clear();
}

void
print_colorized(CPChar pStr, i32 pColF, i32 pColB) {
    while (*pStr != 0x00)
    {
        if (*pStr == 0x0A)
        {
            _K_T_CPOS_Y++;
            _K_T_CPOS_X = 0;
            *pStr++;
            continue;
        }

        _K_T_set_char(*pStr++, pColF, pColB, _K_T_CPOS_X++, _K_T_CPOS_Y);
    }
}
