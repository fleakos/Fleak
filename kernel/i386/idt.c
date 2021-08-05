#include "../../include/machine/idt.h"


idt_entry idt_entries[256] ; 
idt_ptr IDT ;



void init_idt() { 

	IDT.limit = sizeof(idt_entry) * 256 -1;
   	IDT.base  = (unsigned int )&idt_entries;

	//memset(&idt_entries , 0, sizeof(idt_entry)*256) ;// Setting 0 on all fields on all structs . 


	/*by default IRQs mapping are IRQ 0..7  :int 0x8 ... int 0xF ,and 8..15 : 0x70 .. 0x77
	 they conflict with the interrupts used by The CPU to signal exceptions
	normal thing to do is remap them . IRQs remap IRQ0--> 0x20(32) after the isrs  */

	remap_irq() ;
	
	/*Setting up the ISRs */

	idt_set_entry( 0, (unsigned int )isr0 , 0x08, 0x8E);
    	idt_set_entry( 1, (unsigned int )isr1 , 0x08, 0x8E);
    	idt_set_entry( 2, (unsigned int )isr2 , 0x08, 0x8E);
    	idt_set_entry( 3, (unsigned int )isr3 , 0x08, 0x8E);
    	idt_set_entry( 4, (unsigned int )isr4 , 0x08, 0x8E);
    	idt_set_entry( 5, (unsigned int )isr5 , 0x08, 0x8E);
    	idt_set_entry( 6, (unsigned int )isr6 , 0x08, 0x8E);
    	idt_set_entry( 7, (unsigned int )isr7 , 0x08, 0x8E);
    	idt_set_entry( 8, (unsigned int )isr8 , 0x08, 0x8E);
    	idt_set_entry( 9, (unsigned int )isr9 , 0x08, 0x8E);
    	idt_set_entry(10, (unsigned int )isr10, 0x08, 0x8E);
    	idt_set_entry(11, (unsigned int )isr11, 0x08, 0x8E);
	idt_set_entry(12, (unsigned int )isr12, 0x08, 0x8E);
    	idt_set_entry(13, (unsigned int )isr13, 0x08, 0x8E);
    	idt_set_entry(14, (unsigned int )isr14, 0x08, 0x8E);
    	idt_set_entry(15, (unsigned int )isr15, 0x08, 0x8E);
    	idt_set_entry(16, (unsigned int )isr16, 0x08, 0x8E);
    	idt_set_entry(17, (unsigned int )isr17, 0x08, 0x8E);
    	idt_set_entry(18, (unsigned int )isr18, 0x08, 0x8E);
    	idt_set_entry(19, (unsigned int )isr19, 0x08, 0x8E);
    	idt_set_entry(20, (unsigned int )isr20, 0x08, 0x8E);
    	idt_set_entry(21, (unsigned int )isr21, 0x08, 0x8E);
    	idt_set_entry(22, (unsigned int )isr22, 0x08, 0x8E);
    	idt_set_entry(23, (unsigned int )isr23, 0x08, 0x8E);
    	idt_set_entry(24, (unsigned int )isr24, 0x08, 0x8E);
    	idt_set_entry(25, (unsigned int )isr25, 0x08, 0x8E);
    	idt_set_entry(26, (unsigned int )isr26, 0x08, 0x8E);
    	idt_set_entry(27, (unsigned int )isr27, 0x08, 0x8E);
    	idt_set_entry(28, (unsigned int )isr28, 0x08, 0x8E);
    	idt_set_entry(29, (unsigned int )isr29, 0x08, 0x8E);
    	idt_set_entry(30, (unsigned int )isr30, 0x08, 0x8E);
    	idt_set_entry(31, (unsigned int )isr31, 0x08, 0x8E);

		

	//Setting up the IRQs
	idt_set_entry(32, (unsigned int )irq0, 0x08, 0x8E);
	idt_set_entry(33, (unsigned int )irq1, 0x08, 0x8E);
	idt_set_entry(34, (unsigned int )irq2, 0x08, 0x8E);
	idt_set_entry(35, (unsigned int )irq3, 0x08, 0x8E);
	idt_set_entry(36, (unsigned int )irq4, 0x08, 0x8E);
	idt_set_entry(37, (unsigned int )irq5, 0x08, 0x8E);
	idt_set_entry(38, (unsigned int )irq6, 0x08, 0x8E);
	idt_set_entry(39, (unsigned int )irq7, 0x08, 0x8E);
	idt_set_entry(40, (unsigned int )irq8, 0x08, 0x8E);
	idt_set_entry(41, (unsigned int )irq9, 0x08, 0x8E);
	idt_set_entry(42, (unsigned int )irq10, 0x08, 0x8E);
	idt_set_entry(43, (unsigned int )irq11, 0x08, 0x8E);
	idt_set_entry(44, (unsigned int )irq12, 0x08, 0x8E);
	idt_set_entry(45, (unsigned int )irq13, 0x08, 0x8E);
	idt_set_entry(46, (unsigned int )irq14, 0x08, 0x8E);
	idt_set_entry(47, (unsigned int )irq15, 0x08, 0x8E);


    	idt_flush((unsigned int )&IDT); 
}

// Setting up bits in correct position for each entry 
static void idt_set_entry(unsigned char num, unsigned int  base, unsigned short sel, unsigned char flags)
{
   idt_entries[num].base_lo = base & 0xFFFF;
   idt_entries[num].base_hi = (base >> 16) & 0xFFFF;

   idt_entries[num].selector     = sel;
   idt_entries[num].always0 = 0;
   // We must uncomment the OR below when we get to using user-mode.
   // It sets the interrupt gate's privilege level to 3.
   idt_entries[num].flags   = flags /* | 0x60 */;
}
