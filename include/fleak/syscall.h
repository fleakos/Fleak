#ifndef _SYSCALL_H_
#define _SYSCALL_H_

/* syscall_table */

enum{
    SYS_fork,
    SYS_exit,
    SYS_read,
    SYS_kill,
    SYS_sleep,
    SYS_open,
    SYS_write,
    SYS_close,
    SYS_time
};

#endif /* _SYSCALL_H_ */