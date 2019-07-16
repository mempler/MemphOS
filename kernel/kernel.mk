CC=i686-elf-gcc
LD=ld

BUILD=../build
BK=$(BUILD)/kernel
SRC=src
INCLUDE=include

SRC_FILES=\
	$(SRC)/kernel.c $(SRC)/stdio.c $(SRC)/string.c \
	$(SRC)/drivers/VGA.c

ARGS=-static -I $(INCLUDE) -nostdlib -T link.ld -ffreestanding


all : kernel

kernel : make_dirs
	@nasm -felf32 boot.asm -o$(BK)/bsm.o
	@$(CC) -m32 \
		$(SRC_FILES) \
		$(BK)/bsm.o \
		-o $(BUILD)/kernel.bin \
		$(ARGS)

make_dirs :
	@mkdir $(BK)
