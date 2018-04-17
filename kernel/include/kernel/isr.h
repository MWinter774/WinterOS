#ifndef _KERNEL_ISR_H
#define _KERNEL_ISR_H

typedef struct __attribute__((packed))
{
	unsigned int ds, edi, esi, ebp, esp, ebx, edx, ecx, eax;
	unsigned int int_no, error_code;
} stack_state_after_interrupt_t;

#endif /* end of include guard: _KERNEL_ISR_H */
