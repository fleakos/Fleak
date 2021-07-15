#ifndef _SYSCALL_H_
#define _SYSCALL_H_

/* syscall_table */

enum{
    SYS_read,
    SYS_open,
    SYS_write,
    SYS_close,
    SYS_fork
};

/* 
* table of syscalls:
*
* SYS_call_read
* SYS_call_open
* SYS_call_write
* SYS_call_close
* SYS_call_fork
*/

void syscall_entry(void);
void syscall(void);

#endif /* _SYSCALL_H_ */