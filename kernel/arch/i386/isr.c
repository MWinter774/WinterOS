#include <kernel/isr.h>
#include <stdio.h>

void isr_handler(stack_state_after_interrupt_t regs)
{
  printf("ds:%d, edi:%d, esi:%d, ebp:%d, esp:%d, ebx:%d, edx:%d, ecx:%d, eax:%d, int_no:%d, error_code:%d\n",
  regs.ds, regs.edi, regs.esi, regs.ebp, regs.esp, regs.ebx, regs.edx, regs.ecx, regs.eax, regs.int_no, regs.error_code);
}
