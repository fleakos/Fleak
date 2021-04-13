/* (c) Andrew Stuart Tannembaum 1992 */
#ifndef _SYSCODE_H
#define _SYSCODE_H

#define EXIT     1 
#define FORK     2 
#define READ     3 
#define WRITE    4 
#define OPEN     5 
#define CLOSE    6 
#define WAIT     7
#define CREAT    8 
#define LINK     9 
#define UNLINK  10 
#define CHDIR   12 
#define TIME    13
#define MKNOD   14 
#define CHMOD   15 
#define CHOWN   16 
#define BRK	    17
#define STAT    18 
#define LSEEK	19
#define GETPID	20
#define MOUNT	21 
#define UMOUNT	22 
#define SETUID	23
#define GETUID	24
#define STIME	25
#define ALARM	27
#define FSTAT	28 
#define PAUSE	29
#define UTIME	30 
#define ACCESS	33 
#define SYNC	36 
#define KILL	37
#define DUP	    41 
#define PIPE    42 
#define TIMES   43
#define SETGID  46
#define GETGID  47
#define SIGNAL  48
#define IOCTL   54
#define EXEC    59
#define UMASK   60 
#define CHROOT  61
#define KSIG	64
#define UNPAUSE 65
#define BRK2	66
#define REVIVE  67
#define TASKR   68

#endif /* _SYSCODE_H */