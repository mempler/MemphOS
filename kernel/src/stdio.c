#include <stdio.h>
#include <drivers/VGA.h>

// Higher level Definition

void
print(const char* pStr) {
    _K_VGA_print(pStr);
}

void
clear() {
    _K_VGA_clear();
}

void
print_colorized(const char* pStr, uint8_t pColF, uint8_t pColB) {
    _K_VGA_print_colorized(pStr, pColF, pColB);
}
