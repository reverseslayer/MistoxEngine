SOURCES=boot.o kernel.o
	
all: $(SOURCES) MistoxEngine

boot.o:
	i686-elf-as boot.s -o boot.o

kernel.o:
	i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

MistoxEngine:
	i686-elf-gcc -T linker.ld -o MistoxEngine.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc

clean:
	rm -f *.o kernel