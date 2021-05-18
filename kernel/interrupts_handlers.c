#include "isr.h"

void irq_handler(registers reg ) {
    // Here irq handlers should be handled , with some sort of array  points to functions for every number interrupt 


    /* Send end of interrupt signal to PICs */ 
	/* Checking if interrupt involved the slave */

    if(reg.int_no >= 40) { 
		
		EOI(0xA0) ; /* 0xA0 port for slave */
	}

	/* Sending end of interrupt to master */
	EOI(0x20) ;/* 0x20 port for master*/

    return  ; 
}



void isr_handler() {
    
    // Here interrupts service routines should be handled , CPU Exceptions and faults . 
    return ; 
}