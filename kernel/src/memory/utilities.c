#include "memory.h"

u32 _LC_M_free_mem_addr = 0x10000;

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
