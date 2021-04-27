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

	$(CC) -m32 -T boot/link.ld -o fleakos.bin -ffreestanding -O2 -nostdlib boot/boot.o kernel/kernel.o -lgcc -fno-pic

	sudo cp fleakos.bin isodir/boot/fleakos.bin

	grub-mkrescue -o fleakos.iso isodir
	qemu-system-i386 -kernel fleakos.iso

clean:
	@echo "---------------------"
	@echo "Cleaning..."
	rm -r *.o
	rm -r *.iso
	rm -r *.bin

