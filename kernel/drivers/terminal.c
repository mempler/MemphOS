#define KTERM_NOCONST

#include "terminal.h"

#define ADDR_VGA 0xb8000

const i32 CCOL_BLACK         = 0x00;
const i32 CCOL_BLUE          = 0x01;
const i32 CCOL_GREEN         = 0x02;
const i32 CCOL_CYAN          = 0x03;
const i32 CCOL_RED           = 0x04;
const i32 CCOL_MAGENTA       = 0x05;
const i32 CCOL_BROWN         = 0x06;
const i32 CCOL_LIGHT_GRAY    = 0x07;
const i32 CCOL_DARK_GRAY     = 0x08;
const i32 CCOL_LIGHT_BLUE    = 0x09;
const i32 CCOL_LIGHT_GREEN   = 0x0A;
const i32 CCOL_LIGHT_CYAN    = 0x0B;
const i32 CCOL_LIGHT_RED     = 0x0C;
const i32 CCOL_LIGHT_MAGENTA = 0x0D;
const i32 CCOL_YELLOW        = 0x0E;
const i32 CCOL_WHITE         = 0x0F;

// _K_T_ = Kernel Terminal

i32 _K_T_CPOS_X = 0; // KERNEL TERMINAL CONSOLE POSITION X
i32 _K_T_CPOS_Y = 0; // KERNEL TERMINAL CONSOLE POSITION Y


// Set a Character on Position X and Y
void
_K_T_set_char(i8 pC, i32 pColF, i32 pColB, i32 pX, i32 pY) {
     u16 attrib = (pColB << 4) | (pColF & 0x0F);
     volatile u16 *where = (volatile u16 *) ADDR_VGA + (pY * 80 + pX) ;
     *where = pC | (attrib << 8);
}

void
_K_T_print(CPChar pStr, i32 pColF, i32 pColB) {
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

void
_K_T_clear() {
    for (u32 i = 0; i < 0x0fa0; i++)
    {
        _K_T_set_char(0x00, CCOL_LIGHT_GRAY, 0x00, i, 0);
    }
    
    _K_T_CPOS_X = 0;
    _K_T_CPOS_Y = 0;
}

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
