#ifndef _KERNEL_ISR_H
#define _KERNEL_ISR_H
#include <stddef.h>

typedef struct __attribute__((packed))
{
	unsigned int ds, edi, esi, ebp, esp, ebx, edx, ecx, eax;
	unsigned int int_no, error_code;
} stack_state_after_interrupt_t;

void register_irq_callback(size_t irqNum, void (*callback)());

#endif /* end of include guard: _KERNEL_ISR_H */
