#ifndef H_KERNEL_VGA
#define H_KERNEL_VGA

#include <types.h>

enum VGA_COLORS {
    VGA_FOREGROUND_BLACK         = 0x00,
    VGA_FOREGROUND_BLUE          = 0x01,
    VGA_FOREGROUND_GREEN         = 0x02,
    VGA_FOREGROUND_CYAN          = 0x03,
    VGA_FOREGROUND_RED           = 0x04,
    VGA_FOREGROUND_MAGENTA       = 0x05,
    VGA_FOREGROUND_BROWN         = 0x06,
    VGA_FOREGROUND_LIGHT_GRAY    = 0x07,
    VGA_FOREGROUND_DARK_GRAY     = 0x08,
    VGA_FOREGROUND_LIGHT_BLUE    = 0x09,
    VGA_FOREGROUND_LIGHT_GREEN   = 0x0A,
    VGA_FOREGROUND_LIGHT_CYAN    = 0x0B,
    VGA_FOREGROUND_LIGHT_RED     = 0x0C,
    VGA_FOREGROUND_LIGHT_MAGENTA = 0x0D,
    VGA_FOREGROUND_YELLOW        = 0x0E,
    VGA_FOREGROUND_WHITE         = 0x0F,
};

void _K_VGA_set_char(uint8_t pC, uint8_t pColF, uint8_t pColB, int32_t pX, int32_t pY);
void _K_VGA_clear();

#endif