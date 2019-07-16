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
