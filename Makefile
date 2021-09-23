
	######################################################################
	#                       Makefile for Fleak OS ver: 0.0.4					        #
	#                       Copyright(c) 09/04/2021					                 #
	#                       Fleak foundation                     							 #
	######################################################################
	# If you are running on Linux, must change the syntax of some        #
	# instructions as: 'for', 'mkdir', or the path to some programs      #
	# like: 'mkisofs', 'gcc', 'nasm', etc...                             #
	# Also must change the '\' to '/'               					                # 
	# This script is not compatible in Windows.                          #
	######################################################################
	

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

