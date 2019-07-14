#include "mem.h"

void
memcpy(void* pSrc, void* pDest, size pLen) {
    for (size i = 0; i < pLen; i++)
        *((PChar) pDest + i) = *((PChar) pSrc + i);
}

void
memset(void* pDest, u8 pVal, size pLen) {
    PChar temp = (PChar) pDest;

    for ( ; pLen != 0; pLen--)
        *temp++ = pVal;
}


u32 free_mem_addr = 0x10000;

// Todo: make a more smart solution, as this is highly limited
void*
kmalloc(size size)
{
    if (free_mem_addr & 0xFFFFF000) {
        free_mem_addr &= 0xFFFFF000;
        free_mem_addr += 0x1000;
    }

    u32 ret = free_mem_addr;
    free_mem_addr += size;

    return (void*) ret;
}
