#ifndef LIBC_TYPES
#define LIBC_TYPES

typedef char  i8;
typedef short i16;
typedef int   i32;
typedef long  i64;

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long  u64;

typedef u64    size;
typedef float  f32;
typedef double f64;

typedef u8* PChar;
typedef const u8* CPChar;

#define NULL (void*) 0x00

#endif