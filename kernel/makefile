SOURCES=boot.o kernel.o
	
all: $(SOURCES) MistoxEngine

boot.o:
	nasm -felf32 boot.asm -o boot.o

kernel.o:
	i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

MistoxEngine:
	i686-elf-gcc -ffreestanding -nostdlib -g -T linker.ld boot.o kernel.o -lgcc
	
clean:
	rm -f *.o kernel