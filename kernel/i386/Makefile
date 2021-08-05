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
	
all: all-c

all-c: 
	$(CC) -c gdt.c $(CFLAGS) -o gdt.o 
    $(CC) -c idt.c $(CFLAGS) -o idt.o 