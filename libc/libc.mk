CC=gcc
ASM=nasm
LD=ld
AR=ar
BUILD=../build
ARGS=-static -I../kernel -fno-builtin

all : memory link_everything

memory : make_dirs
	$(CC) -m32 -c memory/mem.c -o $(BUILD)/libc/mem.o $(ARGS)

link_everything : memory
	ar rcs $(BUILD)/libc.a $(BUILD)/libc/mem.o

make_dirs :
	mkdir $(BUILD)
	mkdir $(BUILD)/libc
