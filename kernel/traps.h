// Processor-defined:
#ifndef _TRAPS
#define _TRAPS

enum{
    T_ALIGN,
    T_BOUND,
    T_BRKPT,
    T_DBLFLT,
    T_DEFAULT,
    T_DIVIDE,
    T_DEBUG,
    T_FPERR,
    T_GPFLT,
    T_ILLOP,
    T_MCHK,
    T_NMI,
    T_OFLOW,
    T_PGFLT,
    T_SEGNP,
    T_SIMDERR,
    T_STACK,
    T_SYSCALL,
    T_TSS
}; 

#endif