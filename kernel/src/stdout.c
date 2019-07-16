#include <stdout.h>
#include <drivers/VGA.h>

extern uint8_t _K_VGA_CPOS_X;
extern uint8_t _K_VGA_CPOS_Y;

void
print(const char* pStr) {
    print_colorized(pStr, VGA_FOREGROUND_LIGHT_GRAY, 0x00);
}

void
clear() {
    _K_VGA_clear();
}

void
print_colorized(const char* pStr, uint8_t pColF, uint8_t pColB) {
    while (*pStr != 0x00)
    {
        if (*pStr == 0x0A)
        {
            _K_VGA_CPOS_Y++;
            _K_VGA_CPOS_X = 0;
            *pStr++;
            continue;
        }

        _K_VGA_set_char(*pStr++, pColF, pColB, _K_VGA_CPOS_X++, _K_VGA_CPOS_Y);
    }
}
