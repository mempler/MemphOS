#ifndef H_KERNEL_TERMINAL
#define H_KERNEL_TERMINAL

#include "../kernel.h"

#ifndef KTERM_NOCONST

// All 16 bit Colors
extern const i32 CCOL_BLACK;
extern const i32 CCOL_BLUE;
extern const i32 CCOL_GREEN;
extern const i32 CCOL_CYAN;
extern const i32 CCOL_RED;
extern const i32 CCOL_MAGENTA;
extern const i32 CCOL_BROWN;
extern const i32 CCOL_LIGHT_GRAY;
extern const i32 CCOL_DARK_GRAY;
extern const i32 CCOL_LIGHT_BLUE;
extern const i32 CCOL_LIGHT_GREEN;
extern const i32 CCOL_LIGHT_CYAN;
extern const i32 CCOL_LIGHT_RED;
extern const i32 CCOL_LIGHT_MAGENTA;
extern const i32 CCOL_YELLOW;
extern const i32 CCOL_WHITE;

#endif

void
print(CPChar pStr);

void
print_colorized(CPChar pStr, i32 pColF, i32 pColB);

void
clear();

#endif