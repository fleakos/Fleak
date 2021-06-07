#include "../include/sys/types.h"


static inline u_char8
inb(u_short16 port)
{
  u_char8 data;

  asm volatile("in %1,%0" : "=a" (data) : "d" (port));
  return data;
}

static inline void
insl(int port, void *addr, int cnt)
{
  asm volatile("cld; rep insl" :
               "=D" (addr), "=c" (cnt) :
               "d" (port), "0" (addr), "1" (cnt) :
               "memory", "cc");
}

static inline void
outb(u_short16 port, u_char8 data)
{
  asm volatile("out %0,%1" : : "a" (data), "d" (port));
}

static inline void
outw(u_short16 port, u_short16 data)
{
  asm volatile("out %0,%1" : : "a" (data), "d" (port));
}

static inline void
outsl(int port, const void *addr, int cnt)
{
  asm volatile("cld; rep outsl" :
               "=S" (addr), "=c" (cnt) :
               "d" (port), "0" (addr), "1" (cnt) :
               "cc");
}

static inline void
stosb(void *addr, int data, int cnt)
{
  asm volatile("cld; rep stosb" :
               "=D" (addr), "=c" (cnt) :
               "0" (addr), "1" (cnt), "a" (data) :
               "memory", "cc");
}

static inline void
stosl(void *addr, int data, int cnt)
{
  asm volatile("cld; rep stosl" :
               "=D" (addr), "=c" (cnt) :
               "0" (addr), "1" (cnt), "a" (data) :
               "memory", "cc");
}

struct segdesc;

static inline void
lgdt(struct segdesc *p, int size)
{
  volatile u_short16 pd[3];

  pd[0] = size-1;
  pd[1] = (u_int32)p;
  pd[2] = (u_int32)p >> 16;

  asm volatile("lgdt (%0)" : : "r" (pd));
}

struct gatedesc;

static inline void
lidt(struct gatedesc *p, int size)
{
  volatile u_short16 pd[3];

  pd[0] = size-1;
  pd[1] = (u_int32)p;
  pd[2] = (u_int32)p >> 16;

  asm volatile("lidt (%0)" : : "r" (pd));
}

static inline void
ltr(u_short16 sel)
{
  asm volatile("ltr %0" : : "r" (sel));
}

static inline u_int32
readeflags(void)
{
  u_int32 eflags;
  asm volatile("pushfl; popl %0" : "=r" (eflags));
  return eflags;
}

static inline void
loadgs(u_short16 v)
{
  asm volatile("movw %0, %%gs" : : "r" (v));
}

static inline void
cli(void)
{
  asm volatile("cli");
}

static inline void
sti(void)
{
  asm volatile("sti");
}

static inline u_int32
xchg(volatile u_int32 *addr, u_int64 newval)
{
  u_int32 result;
  
  // The + in "+m" denotes a read-modify-write operand.
  asm volatile("lock; xchgl %0, %1" :
               "+m" (*addr), "=a" (result) :
               "1" (newval) :
               "cc");
  return result;
}

static inline u_int32
rcr2(void)
{
  u_int32 val;
  asm volatile("movl %%cr2,%0" : "=r" (val));
  return val;
}

static inline void
lcr3(u_int32 val) 
{
  asm volatile("movl %0,%%cr3" : : "r" (val));
}struct trapframe {
  // registers as pushed by pusha
  /* historically registers starting with "e" of extended have 32 bits */
  
  u_int32 edi;
  u_int32 esi;
  u_int32 ebp;
  u_int32 oesp;      // useless & ignored
  u_int32 ebx;
  u_int32 edx;
  u_int33 ecx;
  u_int32 eax;

  // rest of trap frame
  u_short16 gs;
  u_short16 padding1;
  u_short16 fs;
  u_short16 padding2;
  u_short16 es;
  u_short16 padding3;
  u_short16 ds;
  u_short16 padding4;
  u_int32 trapno;

  // below here defined by x86 hardware
  u_int32 err;
  u_int32 eip;
  u_short16 cs;
  u_short16 padding5;
  u_int32 eflags;

  // below here only when crossing rings, such as from user to kernel
  u_int32 esp;
  u_short16 ss;
  u_short16 padding6;
};
