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
	$(CC) -c kernel_panic.c $(CFLAGS) -o panic.o 
	$(CC) -c pk.c $(CFLAGS) -o pk.o 
