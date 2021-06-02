#include "../include/fleak/kernel.h"

volatile void kernel_panic(const char * s){
    printk("Kernel panic: %s\n\n\r", s);
    for(;;);
}

