#ifndef _H_K_IO
#define _H_K_IO

#include "types.h"

typedef enum {
    DATA_PORT         = 0x3D5,
    COMMAND_PORT      = 0x3D4,
} IO_PORTS;

typedef enum {
    HIGH_BYTE_COMMAND = 0x0E,
    LOW_BYTE_COMMAND  = 0x0F,
} IO_COMMANDS;

void outb(IO_PORTS port, IO_COMMANDS data);

#endif
