#include "fleak/kernel.h"

volatile void kernel_panic(const char * s){
    pk("Kernel panic: %s\n\n\r", s);
    for(;;);
}

