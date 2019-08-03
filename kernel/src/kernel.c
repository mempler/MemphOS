#include <kernel.h>
#include <stdio.h>

#include <drivers/VGA.h>
#include <io.h>

void
_k_initialize() {
    _K_VGA_Initialize();
}

void
_k_main()
{
	print("Hello\nWorld!\n");
}
