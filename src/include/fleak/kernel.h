void verify_area(void * addr,int count);
volatile void kernel_panic(const char * str);
int printf(const char * fmt, ...);
int pk(const char * fmt, ...);
int write(unsigned ch,char * buf,int count);
