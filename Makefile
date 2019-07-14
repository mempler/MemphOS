CC=gcc
ASM=nasm
LD=ld
BUILD=build

.PHONY : make_dirs

kernel : make_dirs
	$(ASM) -f elf32 kernel/kernel.asm -o $(BUILD)/ksm.o

	$(CC) -m32 -c kernel/kernel.c -o $(BUILD)/kc.o
	$(CC) -m32 -c kernel/drivers/terminal.c -o $(BUILD)/drivers/tc.o

	$(LD) -m elf_i386 -T kernel/link.ld -o $(BUILD)/kernel.bin \
		$(BUILD)/ksm.o $(BUILD)/kc.o \
		$(BUILD)/drivers/tc.o
	
qemu : kernel
	qemu-system-i386 -kernel $(BUILD)/kernel.bin

make_dirs : clean
	mkdir $(BUILD)
	mkdir $(BUILD)/drivers

clean :
	rm -rf $(BUILD)
