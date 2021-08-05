#include "../../include/machine/gdt.h"

// This function will be defined in IDT_GDT.asm , it will load the GDT pointer
extern void gdt_flush(int) ;

 // initialize gdt with this function
static void init_gdt();

// Set Value for one GDT entry 
static void gdt_set_entry(int,unsigned int,unsigned int,unsigned char,unsigned char);

// (Code Segment & Data Segment ) for Kernel , (Code Segment and Data Segment) for User mode , NULL entry .  
gdt_entry gdt_entries[5] ; 
gdt_ptr GDT ;


static void init_gdt()
{

   GDT.limit = sizeof(gdt_entry) * 5 - 1; // Gets calculated in compilation !
   GDT.base  = (int)&gdt_entries;

   gdt_set_entry(0, 0, 0, 0, 0);                // Null segment
   gdt_set_entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Kernel Code segment
   gdt_set_entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Kernel Data segment
   gdt_set_entry(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); // User mode code segment
   gdt_set_entry(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); // User mode data segment

   gdt_flush((int)&GDT);
}


static void gdt_set_entry(int num, unsigned int base, unsigned int limit, unsigned char access, unsigned char gran)
{
	// Shifting operations for setting all the bits in their place 
   gdt_entries[num].base_low    = (base & 0xFFFF);
   gdt_entries[num].base_middle = (base >> 16) & 0xFF;
   gdt_entries[num].base_high   = (base >> 24) & 0xFF;

   gdt_entries[num].limit_low   = (limit & 0xFFFF);
   gdt_entries[num].granularity = (limit >> 16) & 0x0F;

   gdt_entries[num].granularity |= gran & 0xF0;
   gdt_entries[num].access      = access;
}
