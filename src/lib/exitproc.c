/* Copyright (C) 1991 Linus Torvalds, everyone is permitted to copy and distribute verbatim copies
of this code document, but changing it is not allowed. */

#define __LIBRARY__
#include "unistd.h"

volatile void _exit(int exit_code)
{
	__asm__("int $0x80"::"a" (__NR_exit),"b" (exit_code));
}
