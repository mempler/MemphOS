#define KTERM_NOCONST

#include <drivers/VGA.h>

#define ADDR_VGA 0x000b8000

int16_t _K_VGA_CPOS_X = 0; // KERNEL VGA POSITION X
int16_t _K_VGA_CPOS_Y = 0; // KERNEL VGA POSITION Y

// Set a Character on Position X and Y
void
_K_VGA_set_char(uint8_t pC, uint8_t pColF, uint8_t pColB, int32_t pX, int32_t pY) {
     uint16_t attrib = (pColB << 4) | (pColF & 0x0F);
     volatile uint16_t *where = (volatile uint16_t *) ADDR_VGA + (pY * 80 + pX) ;
     *where = pC | (attrib << 8);
}

void
_K_VGA_clear() {
    for (uint16_t i = 0; i < 0x0fa0; i++)
        _K_VGA_set_char(0x20, VGA_FOREGROUND_LIGHT_GRAY, 0x00, i, 0);

    _K_VGA_CPOS_X = 0;
    _K_VGA_CPOS_Y = 0;
}
