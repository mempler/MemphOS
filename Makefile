CC      = i686-elf-gcc
AS      = nasm
QEMU    = qemu-system-i386

CFLAGS  = -m32 \
		  -Wall -Wextra -Werror -g \
		  -Ikernel/include \
		  -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -c
ASFLAGS = -felf32
LDFLAGS = -Tkernel/link.ld -melf_i386

BUILD   = ./build

SRC_C   = kernel/src/drivers/VGA.c \
		  kernel/src/kernel.c kernel/src/stdio.c kernel/src/string.c
SRC_ASM = kernel/boot.asm kernel/src/io.asm

LIBS    = # no linux libs!
OBJ     = $(SRC_C:%.c=$(BUILD)/%.o)
OBJ_ASM = $(SRC_ASM:%.asm=$(BUILD)/%.o)

CLEAN_FILES = $(OBJ) $(OBJ_ASM) $(BUILD)/kernel.bin

all : qemu


kernel.bin : $(OBJ) $(OBJ_ASM)
	ld $(LDFLAGS) $^ -o $(BUILD)/kernel.bin

memph.iso : kernel.bin
	@mkdir -p $(BUILD)/iso

	@cp -R iso/* $(BUILD)/iso
	@cp $(BUILD)/kernel.bin $(BUILD)/iso/boot/kernel.bin

	@grub-mkrescue -o $(BUILD)/$@ $(BUILD)/iso


$(OBJ): $(SRC_C)
	@mkdir -p $(dir $@);
	$(CC) $(CFLAGS) $(@:build/%.o=%.c) -o $@

$(OBJ_ASM): $(SRC_ASM)
	@mkdir -p $(dir $@);
	$(AS) $(ASFLAGS) $(@:build/%.o=%.asm) -o $@


qemu : kernel.bin
	$(QEMU) -kernel $(BUILD)/kernel.bin -m 128 -s

bochs : memph.iso
	bochs -f bochsrc.txt -q 

clean :
	rm $(CLEAN_FILES)

