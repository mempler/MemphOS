#ifndef H_KERNEL_VGA
#define H_KERNEL_VGA

#include <types.h>

typedef enum {
    VGA_BLACK         = 0x00,
    VGA_BLUE          = 0x01,
    VGA_GREEN         = 0x02,
    VGA_CYAN          = 0x03,
    VGA_RED           = 0x04,
    VGA_MAGENTA       = 0x05,
    VGA_BROWN         = 0x06,
    VGA_LIGHT_GRAY    = 0x07,
    VGA_DARK_GRAY     = 0x08,
    VGA_LIGHT_BLUE    = 0x09,
    VGA_LIGHT_GREEN   = 0x0A,
    VGA_LIGHT_CYAN    = 0x0B,
    VGA_LIGHT_RED     = 0x0C,
    VGA_LIGHT_MAGENTA = 0x0D,
    VGA_YELLOW        = 0x0E,
    VGA_WHITE         = 0x0F,
} VGA_COLORS;

typedef struct {
    int16_t CURRENT_POS_X;
    int16_t CURRENT_POS_Y;

    VGA_COLORS DEFAULT_FG_COL;
    VGA_COLORS DEFAULT_BG_COL;
} VGA_Info;

void _K_VGA_set_char(uint8_t pC, VGA_COLORS pColF, VGA_COLORS pColB, int32_t pX, int32_t pY);
void _K_VGA_print_colorized(const char* pStr, VGA_COLORS pColF, VGA_COLORS pColB);

void _K_VGA_clear();
void _K_VGA_print(const char* pStr) ;
void _K_VGA_Initialize();
void _K_VGA_set_cursor_position(uint8_t pX, uint8_t pY);

#endif