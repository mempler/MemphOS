BUILD=build

.PHONY : make_dirs clean

kernel : make_dirs
	@$(MAKE) -C kernel -f kernel.mk

iso : kernel 
	@$(MAKE) -C iso -f iso.mk



qemu : kernel
	@qemu-system-i386 -kernel $(BUILD)/kernel.bin

qemu_iso : iso
	@qemu-system-i386 -cdrom $(BUILD)/out/memphos.iso


build_tools :
	@$(MAKE) -C vendor -f vendor.mk


make_dirs : clean
	@mkdir $(BUILD)

clean :
	@rm -rf $(BUILD)
