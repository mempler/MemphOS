#include <kernel.h>

#include <drivers/VGA.h>
#include <string.h>
#include <stdout.h>

void
kmain()
{
    clear();

    print("Hello\n");
    print("World");
}
