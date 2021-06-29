#

MAKE = make
LD = ld 
CC = gcc 
NASM = nasm

CFLAGS =  -m32 \
 -ffreestanding \
 -O2 \
 -nostdlib \
 -lgcc \
 -fno-pic

LDFLAGS = -felf32



PHONY := build

build:
 $(MAKE) -C init/
 $(MAKE) -C boot/

 $(CC) -m32 -T boot/link.ld -o fleakos.bin -ffreestanding -O2 -nostdlib boot/boot.o init/kernel.o -lgcc -fno-pic


 grub-mkrescue -o fleakos.iso 
 qemu-system-i386 -cdrom fleakos.iso

clean:
 @echo "---------------------"
 @echo "Cleaning..."
 rm -r init/kernel.o boot/boot.o
 rm -r *.iso
 rm -r *.bin

