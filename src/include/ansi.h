/ * The <ansi.h> header tries to decide whether the compiler is sufficiently
* compatible with Standard C for Minix to take advantage of it, was adapted to FleakOS by Ch4r0nN. If so, the
* _ANSI symbol will be defined (such as 31459). Otherwise, _ANSI will not be defined
* here, but can be defined by applications that want to comply with the rules.
* The magic number in the definition serves to inhibit unnecessary submission
* the rules. (For consistency with the new tests of ’#ifdef _ANSI in
* headers, _ANSI should be set to nothing, but this
* would damage many library routines that use "#if _ANSI".)

* If _ANSI ends up being defined, a macro
*
* _PROTOTYPE (function, params)
*
* will be defined. This macro expands in different ways, generating
* Standard C ANSI prototypes or old style K&R prototypes (Kernighan & Ritchie),
* as needed. Finally, some programs use _CONST, _VOIDSTAR etc.
* in such a way that they are portable in the ANSI and K&R compilers.
* The appropriate macros are defined here.
* /

#ifndef _ANSI_H
#define _ANSI_H

#if __STDC__ == 1
#define _ANSI 31459 / * the compiler requires complete ANSI compliance * /
#endif

#ifdef __GNUC__
#define _ANSI 31459 / * gcc adapts enough, even in non-ANSI mode * /
#endif

#ifdef _ANSI

/* Mantém tudo para prototypes ANSI. */
#define _PROTOTYPE(function, params) function params
#define _ARGS(params) params

#define _VOIDSTAR void *
#define _VOID void
#define _CONST const
#define _VOLATILE volatile
#define _SIZET size_t
#else

#define _PROTOTYPE(function, params) function()
#define _ARGS(params) ()

#define _VOIDSTAR void *
#define _VOID void
#define _CONST
#define _VOLATILE
#define _SIZET int

#endif /* _ANSI */

#define _RESTRICT

#if defined(_FLEAKOS) || _POSIX_C_SOURCE > 0 || defined(_POSIX2_SOURCE)
#undef _POSIX_SOURCE
#define _POSIX_SOURCE 1
#endif

#endif /* ANSI_H */
