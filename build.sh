echo "Compilando arquivo C"
gcc -m32 -c init/main.c -o kernel/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
echo "Compilando bootloader"
nasm -felf32 boot/boot.asm -o boot/boot.o
echo "Linker"
gcc -m32 -T boot/link.ld -o fleakos.bin -ffreestanding -O2 -nostdlib boot/boot.o kernel/kernel.o -lgcc
echo "Copiando arquivo binario para isodir"
cp fleakos.bin isodir/boot/fleakos.bin
echo "Executando o grub"
grub-mkrescue -o fleakos.iso isodir
echo "Entrando no qemu"
qemu-system-i386 -cdrom fleakos.iso