#ifndef H_K_STDOUT
#define H_K_STDOUT

#include <types.h>

void print(const char* pStr);

void print_colorized(const char* pStr, uint8_t pColF, uint8_t pColB);
void clear();

#endif
