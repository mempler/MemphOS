CC=gcc
ASM=nasm
LD=ld

BUILD=../build
BK=$(BUILD)/kernel
SRC=src

ARGS=-static -I../libc/src -nostdlib

all : kernel

kernel : make_dirs
	$(ASM) -f elf32 $(SRC)/boot.asm -o $(BK)/bsm.o

	$(CC) -m32 -c $(SRC)/kernel.c -o $(BK)/kc.o $(ARGS)
	$(CC) -m32 -c $(SRC)/drivers/terminal.c -o $(BK)/drivers/tc.o $(ARGS)

	$(LD) -m elf_i386 -T link.ld -o $(BUILD)/kernel.bin \
		$(BK)/bsm.o $(BK)/kc.o \
		$(BK)/drivers/tc.o \
		$(BUILD)/libc.a
	
make_dirs :
	mkdir $(BK)
	mkdir $(BK)/drivers
