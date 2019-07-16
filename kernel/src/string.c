#include <string.h>

size_t strlen(const char* pStr) {
    uint64_t i = 0;
    while (*pStr++ != 0x00) i++;
    return i;
}

uint32_t _LC_M_free_mem_addr = 0x10000;

void*
kmalloc(size_t pSize)
{
    if (_LC_M_free_mem_addr & 0xFFFFF000) {
        _LC_M_free_mem_addr &= 0xFFFFF000;
        _LC_M_free_mem_addr += 0x1000;
    }

    uint32_t ret = _LC_M_free_mem_addr;
    _LC_M_free_mem_addr += pSize;

    return (void*) ret;
}

void*
memcpy(void* pDst, const void* pSrc, size_t pSize) {
    for (size_t i = 0; i < pSize; i++)
        *((char*) pDst + i) = *((const char*) pSrc + i);

    return pDst;
}

void*
memset(void* pDst, int pVal, size_t pSize) {
    char* temp = (char*) pDst;

    for ( ; pSize != 0; pSize--)
        *temp++ = pVal;

    return pDst;
}
