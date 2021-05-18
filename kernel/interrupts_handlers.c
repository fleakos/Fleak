#include "isr.h"

/* Once installing an ISR for a given interrupt or an IRQ , the installer should call map_handler_interrupt */
isr handlers[256]={0} ; 

void irq_handler(registers reg ) {
   


    	/* Send end of interrupt signal to PICs */ 
	/* Checking if interrupt involved the slave */

    if(reg.int_no >= 40) { 
		
		EOI(0xA0) ; /* 0xA0 port for slave */
	}

	/* Sending end of interrupt to master */
	EOI(0x20) ;/* 0x20 port for master*/
	
	// Checking if interrupt is installed 
	// if so , call its handlers 
	if (handlers[reg.int_no]!=0) handlers[reg.int_no](reg)  ; 

    return  ; 
}


void map_handler_interrupt(unsigned int interrupt_number, isr handler) { // mapping interrupts numbers to convenient handlers
	
	handlers[interrupt_number] = handler ;  

}

void isr_handler() {
    
    // Here interrupts service routines should be handled , CPU Exceptions and faults . 
    return ; 
}
