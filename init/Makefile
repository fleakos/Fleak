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
	$(CC) -m32 -c main.c $(CFLAGS) -o kernel.o
