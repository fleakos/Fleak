#ifndef _ERRNO_H
#define _ERRNO_H

#define ERRGEN 99 /* Generic Error */
#define ERRPERM 1 /* operation not allowed */
#define ERRNOTF 2 /* No such file or directory */
#define ERRPROC 3 /* there is no such process */
#define ERRFUNCALL 4 /* interrupted function call */
#define ERRIO 5 /* Input/Output errors */
#define ERRVICE 6 /* there is no such device or address */
#define ERR2BIG 7 /* argument list too long */
#define ERRXEC 8 /* exec format error */
#define ERRBADF 9 /*  defective file descriptor */
#define ERRCHILD 10 /*  there is no child process */

#define ERRAGAIN 11 /* resource temporarily unavailable */
#define ERRNOMEM 12 /* not enough space */
#define ERRACCES 13 /* permission denied */
#define ERRFAULT 14 /* faulty address */
#define ERRNOTBLK 15 /* Extension: not a special block file */
#define ERRBUSY 16 /* resource busy */
#define ERREXIST 17 /* the file exists */
#define ERRXDEV 18 /* incorrect link */
#define ERRNODEV 19 /* there is no such device */
#define ERRNOTDIR 20 /* is not a directory */
#define ERRISDIR 21 /* is a directory */
#define ERRINVAL 22 /* invalid argument */
#define ERRNFILE 23 /* files too open on the system */
#define ERRMFILE 24 /* files too open */
#define ERRNOTTY 25 /* inadequate I/O control operation */
#define ERRTXTBSY 26 /* is no longer used */
#define ERRFBIG 27 /* file too big */
#define ERRNOSPC 28 /* there is no space left on the device */
#define ERRSPIPE 29 /* invalid search */
#define ERROFS 30 /* read-only file system */
#define ERRMLINK 31 /* too many links */
#define ERRPIPE 32 /* problematic tube */
#define ERRDOM 33 /* do (from standard ANSI C) */
#define ERRANGE 34 /* result too large (from standard C ANSI) */
#define ERRDEADLK 35 /* resource deadlock avoided */
#define ERRNAMETOOLONG 36 /* file name too long */
#define ERRNOLCK 37 /* no locks available */
#define ERRNOSYS 38 /* function not implemented */
#define ERRNOTEMPTY 39 /* non-empty directory */

/* The following errors relate to networking. */
#define ERRPACKSIZE 50 /* invalid packet size for some protocol */
#define ERROUTOFBUFS 51 /* não resfria buffers suficientes */
#define ERRBADIOCTL 52 /* all ready and connected */
#define ERRBADMODE 53 /* ioclt badmode */
#define ERRWOULDBLOCK 54 
#define ERRBADDEST 55 /* não é um endereço de destino válido */
#define ERRDSTNOTRCH 56 /* destino inacessível */
#define ERRISCONN 57 /* all ready and connected */
#define ERRADDRINUSE 58 /* address in use */
#define ERRCONNREFUSED 59 /* connection refused */
#define ERRCONNRESET 60 /* reconfigured connection */
#define ERRTIMEDOUT 61 /* connection expired */
#define ERRURG 62 /* urgent data present */
#define ERRNOURG 63 /* non-urgent data present */
#define ERRNOTCONN 64 /* no connection (still or no more) */
#define ERRSHUTDOWN 65 /* a write call for an undo connection */
#define ERRNOCONN 66 /* there is no such connection */
#define ERRAFNOSUPPORT 67 /* unsupported address family */
#define ERRPROTONOSUPPORT 68 /* protocol not supported by AF */
#define ERRPROTOTYPE 69 /* wrong protocol type for the socket */
#define ERRINPROGRESS 70 /* Operation in progress now */
#define ERRADDRNOTAVAIL 71 /* Unable to assign requested address */
#define ERRALREADY 72 /* Connection already in progress */
#define ERRMSGSIZE 73 /* Message too long */

/* POSIX error. */
#define ERRLOCKED 101 /* unable to send message due to deadlock */
#define ERRBADCALL 102 /* invalid system call number */
#define ERRBADSRCDST 103 /* damaged source or destination process */
#define ERRCALLDENIED 104 /* does not have permission for the system call */
#define ERRDEADDST 105 /* sending destination is not active */
#define ERRNOTREADY 106 /* source or destination is not ready */
#define ERRBADREQUEST 107 /* the destination cannot handle the request */
#define ERRDONTREPLY 201 /* pseudo-code: do not send a reply */
#endif /* _ERRNO_H */
