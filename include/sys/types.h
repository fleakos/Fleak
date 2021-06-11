#ifndef _TYPES_H_
#define _TYPES_H_

#ifndef _SIZE_T
#define _SIZE_T

typedef unsigned int size_t;
#endif /* _SIZE_T */

#ifndef _NULL
#define _NULL

#define NULL ((void *)0)
#endif /* _NULL */

#ifdef _TYPES
#define _TYPES

/*
arch Align: char short int long ptr long-long u8 u16 u32 u64
i386 1 2 4 4 4 4 1 2 4 4
i686 1 2 4 4 4 4 1 2 4 4
alpha 1 2 4 8 8 8 1 2 4 8
armv4l 1 2 4 4 4 4 1 2 4 4
ia64 1 2 4 8 8 8 1 2 4 8
mips 1 2 4 4 4 8 1 2 4 8
ppc 1 2 4 4 4 8 1 2 4 8
sparc 1 2 4 4 4 8 1 2 4 8
sparc64 1 2 4 4 4 8 1 2 4 8
x86_64 1 2 4 8 8 8 1 2 4 8
kernel: arch Align: char short int long ptr long-long u_char8 u_short16 u_int32 u_long64
kernel: sparc64 1 2 4 8 8 8 1 2 4 8
*/

typedef unsigned int u_int32;
typedef unsigned short u_short16;
typedef unsigned long u_long64;
typedef unsigned char u_char8;
#endif /* _TYPES */

#ifndef _WCHAR_T_
#define _WCHAR_T_

/* Thus, the wchar_t data type is the same 
*    as an unsigned short integer: 16 bits wide. 
*/

typedef unsigned short wchar_t;
#endif /* _WCHAR_T_ */
#endif /* _TYPES_H_ */