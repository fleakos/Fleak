#ifndef _ERRTURN_H
#define _ERRTURN_H

extern int errno;
char *error_message[NERROR+1] = {
        "Error 0",
        "Not owner",
        "No such file or directory",
        "No such process",
        "Interrupted system call",
        "I/O error",
        "No such device or address",
        "Arg list too long",
        "Exec format error",
        "Bad file number",
        "No children",
        "No more processes",
        "Not enough core",
        "Permission denied",
        "Bad address",
        "Block device required",
        "Mount device busy",
        "File exists",
        "Cross-device link",
        "No such device",
        "Not a directory",
        "Is a directory",
        "Invalid argument",
        "File table overflow",
        "Too many open files",
        "Not a typewriter",
        "Text file busy",
        "File too large",
        "No space left on device",
        "Illegal seek",
        "Read-only file system",
        "Too many links",
        "Broken pipe",
        "Math argument",
        "Result too large"
};
#endif /*_ERRTURN_H*/
