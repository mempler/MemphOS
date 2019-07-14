#ifndef LIBC_MEM_H
#define LIBC_MEM_H

#include <types.h>
#include <kernel.h>

void  memcpy(void* pSrc, void* pDest, size pLen);
void  memset(void* pDest, u8 pVal, size pLen);
void* kmalloc(size size);

#endif