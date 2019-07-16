CC=gcc
ASM=nasm
LD=ld

BUILD=../build
BK=$(BUILD)/kernel
SRC=src

SRC_FILES=$(SRC)/kernel.c $(SRC)/drivers/terminal.c $(SRC)/memory/utilities.c

ARGS=-static -I../libc/src -nostdlib -T link.ld

all : kernel

kernel : make_dirs
	@$(ASM) -f elf32 $(SRC)/boot.asm -o $(BK)/bsm.o
	@$(CC) -m32 \
		$(SRC_FILES) \
		$(BUILD)/libc.a $(BK)/bsm.o \
		-o $(BUILD)/kernel.bin \
		$(ARGS)
	
make_dirs :
	@mkdir $(BK)
