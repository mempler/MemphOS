#include "mem.h"

struct Page {
    
};

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


u32 _LC_M_free_mem_addr = 0x10000;
// Todo: make a more smart solution, as this is highly limited
void*
kmalloc(size pSize)
{
    if (_LC_M_free_mem_addr & 0xFFFFF000) {
        _LC_M_free_mem_addr &= 0xFFFFF000;
        _LC_M_free_mem_addr += 0x1000;
    }

    u32 ret = _LC_M_free_mem_addr;
    _LC_M_free_mem_addr += pSize;

    return (void*) ret;
}
