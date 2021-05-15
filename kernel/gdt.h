#ifndef GDT_H
#define GDT_H

struct gdt_entry_struct
{
   unsigned short limit_low;           // The lower 16 bits of the limit.
   unsigned short base_low;            // The lower 16 bits of the base.
   unsigned char base_middle;         // The next 8 bits of the base.
   unsigned char access;              // Access flags, determine what ring this segment can be used in.
   unsigned char granularity;
   unsigned char base_high;           // The last 8 bits of the base.
} __attribute__((packed));

typedef struct gdt_entry_struct gdt_entry;

// Default struct to tell the processor where to find our GDT 
struct gdt_ptr_struct
{
   unsigned short limit;               // The upper 16 bits of all selector limits.
   unsigned int base;                // The address of the first gdt_entry.
} __attribute__((packed));
typedef struct gdt_ptr_struct gdt_ptr;
// END GDT 


#endif