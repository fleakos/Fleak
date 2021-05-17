/* Copyright (c) 2021 Ch4r0nN/Gr3n0xX */

#ifndef _STDIO_H_
#define _STDIO_H_

#define stdin 0
#define stdout 1
#define stderr 2


typedef unsigned int *FILE


int printf(const char *fmt, ...);

int scanf(char *format, unsigned args);

int fgets(char *str, int num);

char gett(void);

#endif /* TYPES */
#endif /* _STDIO_H_ */
