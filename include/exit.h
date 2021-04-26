/* exit.h (c) 2021 Ch4r0nN/Gr3n0xX */
#ifndef _EXIT_H_
#define _EXIT_H_

#define SYSCALL_PARAM(F_exit, E_proc)
    __asm__("int $0x80" :: "a" (F_exit), "b" (E_proc));

#endif /*_EXIT_H*/
