echo "Compilando arquivo C"
gcc -m32 -c init/main.c -o kernel/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
echo "Compiling bootloader"
nasm -felf32 boot/boot.asm -o boot/boot.o
echo "Linker"
gcc -m32 -T boot/link.ld -o fleakos.bin -ffreestanding -O2 -nostdlib boot/boot.o kernel/kernel.o -lgcc
echo "Copying binary file to isodir"
cp fleakos.bin isodir/boot/fleakos.bin
echo "Running the grub"
grub-mkrescue -o fleakos.iso isodir
echo "Entering no qemu"
qemu-system-i386 -cdrom fleakos.iso