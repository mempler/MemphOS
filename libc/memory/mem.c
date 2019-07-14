#include "mem.h"

void
memcpy(void* pSrc, void* pDest, size pLen) {
    for (size i = 0; i < pLen; i++)
        *((u8*) pDest + i) = *((u8*) pSrc + i);
}

void
memset(void* pDest, u8 pVal, size pLen) {
    u8 *temp = (u8 *) pDest;

    for ( ; pLen != 0; pLen--)
        *temp++ = pVal;
}
