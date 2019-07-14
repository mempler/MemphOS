CC=gcc
ASM=nasm
LD=ld
AR=ar
BUILD=../build
ARGS=-static -I../kernel -I./ -fno-builtin

all : memory link_everything

memory : make_dirs
	$(CC) -m32 -c memory/mem.c -o $(BUILD)/libc/mem.o $(ARGS)
	$(CC) -m32 -c memory/string.c -o $(BUILD)/libc/string.o $(ARGS)

link_everything : memory
	ar rcs $(BUILD)/libc.a $(BUILD)/libc/mem.o $(BUILD)/libc/string.o

make_dirs :
	mkdir $(BUILD)/libc
