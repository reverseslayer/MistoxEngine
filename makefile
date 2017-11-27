CSOURCES=$(shell find src -type f -name "*.c")
ASOURCES=$(shell find src/assembly -type f -name "*.asm")
HSOURCES=$(shell find src/include -type f -name "*.h")

COBJ=$(patsubst %.c,%.o,$(CSOURCES))
AOBJ=$(patsubst %.asm,%.o,$(ASOURCES))

Clear: MistoxOs.iso
	rm -f *.bin
	rm -r iso
	rm -f src/*.o
	rm -f src/assembly/*.o

MistoxOs.iso: Mistox.bin
	rm -f *.iso
	mkdir -p iso/boot/grub
	cp Mistox.bin iso/boot/Mistox.bin
	cp grub/menu.lst iso/boot/grub/menu.lst
	cp grub/stage2_eltorito iso/boot/grub/stage2_eltorito
	genisoimage -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -boot-info-table -o MistoxOs.iso iso

Mistox.bin: $(CSOURCES) $(ASOURCES) $(COBJ) $(AOBJ)
	i686-elf-gcc -T src/assembly/linker.ld $(AOBJ) $(COBJ) -o Mistox.bin -ffreestanding -O2 -nostdlib $(SOURCES) -lgcc

%.o: %.c
	i686-elf-gcc -c $< -o $@ -std=gnu99 -ffreestanding -O2 -Wall -Wextra

%.o: %.asm
	nasm -felf32 -o $@ $<