
BUILD=../build
BO=$(BUILD)/out
BISO=$(BUILD)/iso

ISONAME=memphos

all : build_iso


build_iso : make_dirs
	@cp -R content/* $(BISO)
	@cp $(BUILD)/kernel.bin $(BISO)/kernel.bin

	@grub-mkrescue -o $(BO)/$(ISONAME).iso $(BISO)

make_dirs :
	@mkdir $(BO)
	@mkdir $(BISO)
