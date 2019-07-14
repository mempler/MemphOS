#include "kernel.h"
#include "drivers/terminal.h"

void
kmain()
{
    clear();

    print("Hello\n");
    print("World");
}
