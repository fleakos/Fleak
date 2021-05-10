#ifndef _FLEAK_KERNEL_H
#define _FLEAK_KERNEL_H

void verify_area(void * addr,int count);

void kernel_panic(const char * str);

int printf(const char * fmt, ...);

int printk(const char * fmt, ...);

int write(unsigned ch,char * buf,int count);

#endif /* _FLEAK_KERNEL_H */
