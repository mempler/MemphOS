#ifndef LIBC_STDOUT
#define LIBC_STDOUT

#include "types.h"

void
print(CPChar pStr);

void
print_colorized(CPChar pStr, i32 pColF, i32 pColB);

void
clear();

#endif