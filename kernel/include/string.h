#ifndef K_M_STR_H
#define K_M_STR_H

#include <types.h>

void* memcpy(void* pDst, const void* pSrc, size_t pSize);
void* memset(void* pDst, int pVal, size_t pSize);

void* kmalloc(size_t pSize);

size_t strlen(const char* pStr);

#endif
