#ifndef _KERNEL_INIT_IDT_H
#define _KERNEL_INIT_IDT_H

typedef struct __attribute__((packed))
{
    unsigned short base_low;
    unsigned short selector;
    unsigned char  always0;
    unsigned char  flags;
    unsigned short base_high;
} idt_entry_t;

typedef struct __attribute__((packed))
{
    unsigned short limit;
    unsigned int base;
} idt_ptr_t;

/*
Initializes the IDT.
*/
void kernel_init_idt();


#endif /* end of include guard: _KERNEL_INIT_IDT_H */
