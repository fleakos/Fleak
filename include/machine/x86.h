#include "../include/sys/types.h"


static inline u_char
inb(u_short port)
{
  u_char data;

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
outb(u_short port, u_char data)
{
  asm volatile("out %0,%1" : : "a" (data), "d" (port));
}

static inline void
outw(u_short port, u_short data)
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
  volatile ushort pd[3];

  pd[0] = size-1;
  pd[1] = (uint)p;
  pd[2] = (uint)p >> 16;

  asm volatile("lgdt (%0)" : : "r" (pd));
}

struct gatedesc;

static inline void
lidt(struct gatedesc *p, int size)
{
  volatile ushort pd[3];

  pd[0] = size-1;
  pd[1] = (uint)p;
  pd[2] = (uint)p >> 16;

  asm volatile("lidt (%0)" : : "r" (pd));
}

static inline void
ltr(ushort sel)
{
  asm volatile("ltr %0" : : "r" (sel));
}

static inline uint
readeflags(void)
{
  uint eflags;
  asm volatile("pushfl; popl %0" : "=r" (eflags));
  return eflags;
}

static inline void
loadgs(u_short v)
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

static inline u_int
xchg(volatile u_int *addr, u_int newval)
{
  uint result;
  
  // The + in "+m" denotes a read-modify-write operand.
  asm volatile("lock; xchgl %0, %1" :
               "+m" (*addr), "=a" (result) :
               "1" (newval) :
               "cc");
  return result;
}

static inline u_int
rcr2(void)
{
  u_int val;
  asm volatile("movl %%cr2,%0" : "=r" (val));
  return val;
}

static inline void
lcr3(u_int val) 
{
  asm volatile("movl %0,%%cr3" : : "r" (val));
}struct trapframe {
  // registers as pushed by pusha
  u_int edi;
  u_int esi;
  u_int ebp;
  u_int oesp;      // useless & ignored
  u_int ebx;
  u_int edx;
  u_int ecx;
  u_int eax;

  // rest of trap frame
  u_short gs;
  u_short padding1;
  u_short fs;
  u_short padding2;
  u_short es;
  u_short padding3;
  u_short ds;
  u_short padding4;
  u_int trapno;

  // below here defined by x86 hardware
  u_int err;
  u_int eip;
  u_short cs;
  u_short padding5;
  u_int eflags;

  // below here only when crossing rings, such as from user to kernel
  u_int esp;
  u_short ss;
  u_short padding6;
};
