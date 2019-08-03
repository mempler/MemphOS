#define KTERM_NOCONST

#include <drivers/VGA.h>
#include <io.h>

#define ADDR_VGA 0x000b8000

static
VGA_Info _K_VGA_INFO;

void // Set a Character on Position X and Y
_K_VGA_set_char(uint8_t pC, VGA_COLORS pColF, VGA_COLORS pColB, int32_t pX, int32_t pY) {
     uint16_t attrib = (pColB << 4) | (pColF & 0x0F);

     volatile uint16_t *where = (volatile uint16_t *) ADDR_VGA + (pY * 80 + pX);

     *where = pC | (attrib << 8);
     _K_VGA_set_cursor_position(pX + 1, pY);
}

void
_K_VGA_print_colorized(const char* pStr, VGA_COLORS pColF, VGA_COLORS pColB) {
    while (*pStr != 0x00)
    {
        if (*pStr == 0x0A)
        {
            _K_VGA_INFO.CURRENT_POS_Y++;
            _K_VGA_INFO.CURRENT_POS_X = 0;
            pStr++;
            _K_VGA_set_cursor_position(_K_VGA_INFO.CURRENT_POS_X, _K_VGA_INFO.CURRENT_POS_Y);
            continue;
        }

        _K_VGA_set_char(*pStr++, pColF, pColB, _K_VGA_INFO.CURRENT_POS_X++, _K_VGA_INFO.CURRENT_POS_Y);
    }
}

void
_K_VGA_clear() {
    for (uint16_t i = 0; i < 0x0fa0; i++)
        _K_VGA_set_char(0x20, _K_VGA_INFO.DEFAULT_FG_COL, _K_VGA_INFO.DEFAULT_BG_COL, i, 0);

    _K_VGA_INFO.CURRENT_POS_X = 0;
    _K_VGA_INFO.CURRENT_POS_Y = 0;
}

void
_K_VGA_print(const char* pStr) {
    _K_VGA_print_colorized(pStr,  _K_VGA_INFO.DEFAULT_FG_COL, _K_VGA_INFO.DEFAULT_BG_COL);
}

void // Initialize the VGA Terminal
_K_VGA_Initialize() {
    _K_VGA_INFO.CURRENT_POS_X = 0;
    _K_VGA_INFO.CURRENT_POS_Y = 0;

    _K_VGA_INFO.DEFAULT_FG_COL = VGA_WHITE;
    _K_VGA_INFO.DEFAULT_BG_COL = VGA_MAGENTA;

    _K_VGA_clear();

    // TODO: Do more ?

    _K_VGA_set_cursor_position(0x00, 0x00);
}

void
_K_VGA_set_cursor_position(uint8_t pX, uint8_t pY) {
    uint16_t pos = pX + (pY * 80);

    outb(COMMAND_PORT, HIGH_BYTE_COMMAND);
    outb(DATA_PORT,    ((pos >> 8) & 0x00FF));

    outb(COMMAND_PORT, LOW_BYTE_COMMAND);
    outb(DATA_PORT,    pos & 0x00FF);
}

