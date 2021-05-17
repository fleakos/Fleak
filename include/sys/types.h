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

typedef unsigned int u_int;
typedef unsigned short u_short;
typedef unsigned u_char;
#endif /* _TYPES */

#endif /* _TYPES_H_ */