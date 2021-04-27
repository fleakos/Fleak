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

all: compile

compile:
	$(NASM) $(LDFLAGS) boot.asm -o boot.o
