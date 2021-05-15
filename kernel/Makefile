MAKE = make
LD = ld 
CC = gcc 
NASM = nasm

ASFLAGS=-f elf32

CFLAGS =  -m32 \
	-ffreestanding \
	-O2 \
	-nostdlib \
	-lgcc \
	-fno-pic

all: all-assembly all-c  

all-c: 
	$(CC) -c gdt.c $(CFLAGS) -o gdt.o 
	$(CC) -c kernel_panic.c $(CFLAGS) -o panic.o 

all-assembly:

	$(NASM) $(ASFLAGS) gdt_idt.asm -o gdt_idt.o
