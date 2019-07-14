#include "string.h"

size
strlen(CPChar pStr) {
    size i = 0;
    while (*pStr++ != 0x00) i++;
    return i;
}