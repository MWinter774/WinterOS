#ifndef _KERNEL_GDT_H
#define _KERNEL_GDT_H

typedef struct __attribute__((packed))
{
  unsigned short limit_low;
  unsigned short base_low;
  unsigned char base_middle;
  unsigned char access;
  unsigned char granularity;
  unsigned char base_high;
} gdt_entry_t;

typedef struct __attribute__((packed))
{
  unsigned short limit;
  unsigned int base;
} gdt_ptr_t;

/*
Initializes the gdt.
*/
void kernel_init_gdt();

#endif /* end of include guard: _KERNEL_GDT_H */
