mkdir -p iso/boot/grub
cp MistoxEngine.bin iso/boot/MistoxEngine.bin
cp grub.cfg iso/boot/grub/grub.cfg
grub-mkrescue -o MistoxEngine.iso iso