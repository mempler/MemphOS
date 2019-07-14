#include "kernel.h"
#include "drivers/terminal.h"

#include <memory/mem.h>

void
kmain()
{
    clear();

    print("Hello\n");
    print("World");
}
