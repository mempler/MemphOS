CC=gcc
ASM=nasm
LD=ld
AR=ar

BUILD=../build
BLC=$(BUILD)/libc
SRC=src

ARGS=-static -I../kernel/src -Isrc -nostdlib

all : memory link_everything

memory : make_dirs
	$(CC) -m32 -c $(SRC)/memory/mem.c -o $(BLC)/mem.o $(ARGS)
	$(CC) -m32 -c $(SRC)/memory/string.c -o $(BLC)/string.o $(ARGS)

	$(CC) -m32 -c $(SRC)/stdout.c -o $(BLC)/stdout.o $(ARGS)

link_everything : memory
	ar rcs $(BUILD)/libc.a $(BUILD)/libc/mem.o $(BLC)/string.o  $(BLC)/stdout.o

make_dirs :
	mkdir $(BLC)
