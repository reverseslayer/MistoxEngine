	
Kernel: boot.o kernel.o
	i686-elf-gcc -T link.ld -o MistoxEngine.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc

boot.o: boot.asm
	nasm -felf32 boot.asm -o boot.o

kernel.o: kernel.c
	i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	
clean:
	rm -f *.o kernel