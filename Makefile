CC=gcc
ASM=nasm
LD=ld
BUILD=build
ARGS=-static -I./libc -fno-builtin

.PHONY : make_dirs

libc : clean
	$(MAKE) -C libc -f libc.mk

kernel : make_dirs libc
	$(ASM) -f elf32 kernel/kernel.asm -o $(BUILD)/ksm.o

	$(CC) -m32 -c kernel/kernel.c -o $(BUILD)/kc.o $(ARGS)
	$(CC) -m32 -c kernel/drivers/terminal.c -o $(BUILD)/drivers/tc.o $(ARGS)

	$(LD) -m elf_i386 -T kernel/link.ld -o $(BUILD)/kernel.bin \
		$(BUILD)/ksm.o $(BUILD)/kc.o \
		$(BUILD)/drivers/tc.o \
		$(BUILD)/libc.a
	
qemu : kernel
	qemu-system-i386 -kernel $(BUILD)/kernel.bin

make_dirs : clean
	mkdir $(BUILD)
	mkdir $(BUILD)/drivers

clean :
	rm -rf $(BUILD)

