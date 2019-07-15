BUILD=build

.PHONY : make_dirs clean

libc : make_dirs
	$(MAKE) -C libc -f libc.mk

kernel : make_dirs libc
	$(MAKE) -C kernel -f kernel.mk

iso : kernel 
	$(MAKE) -C iso -f iso.mk

qemu : kernel
	qemu-system-i386 -kernel $(BUILD)/kernel.bin

qemu_iso : iso
	qemu-system-i386 -cdrom $(BUILD)/out/memphos.iso

make_dirs : clean
	mkdir $(BUILD)

clean :
	rm -rf $(BUILD)

