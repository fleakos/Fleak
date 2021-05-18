#ifndef ISR_H
#define ISR_H


// This struct is based on how the isr_stub will push data into the stack 
typedef struct registers_struct
{
   unsigned int ds;                  // Data segment selector
   unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax; // Pushed by pusha.
   unsigned int int_no, err_code;    
   unsigned int eip, cs, eflags, useresp, ss; // Pushed by the processor automatically.
} registers;

// End of interrupt 
extern void EOI() ;

// Handlers 
typedef void (*isr)(registers) ; 

// Call this function to map an interrupt once installed 
void map_handler_interrupt(unsigned int  Nr_interrupt ,isr handler ) ;


#endif
