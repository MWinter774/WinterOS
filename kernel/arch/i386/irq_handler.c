#include <kernel/isr.h>
#include <stdio.h>
#include <kernel/assembly_wrapper.h>

#define IRQ0 32
#define IRQ1 33
#define IRQ2 34
#define IRQ3 35
#define IRQ4 36
#define IRQ5 37
#define IRQ6 38
#define IRQ7 39
#define IRQ8 40
#define IRQ9 41
#define IRQ10 42
#define IRQ11 43
#define IRQ12 44
#define IRQ13 45
#define IRQ14 46
#define IRQ15 47
#define NUM_IRQS 16

void (*irq_callbacks[NUM_IRQS])() = { NULL };

void irq_handler(stack_state_after_interrupt_t regs)
{
  outb(0x20, 0x20);
  if(regs.int_no >= IRQ8) //if the irq is for the 2nd PIC
  {
    outb(0xA0, 0x20);
  }

  size_t index = regs.int_no - IRQ0;
  if(index >= NUM_IRQS)
  {
    printf("IRQ INDEX OUT OF RANGE: %d!", index);
  }
  else if(irq_callbacks[index] != NULL)
  {
    irq_callbacks[index]();
  }
  else
  {
    printf("Unknown IRQ%d!\n", index);
    printf("ds:%d, edi:%d, esi:%d, ebp:%d, esp:%d, ebx:%d, edx:%d, ecx:%d, eax:%d, int_no:%d, error_code:%d\n",
    regs.ds, regs.edi, regs.esi, regs.ebp, regs.esp, regs.ebx, regs.edx, regs.ecx, regs.eax, regs.int_no, regs.error_code);
  }
}

void register_irq_callback(size_t irqNum, void (*callback)())
{
  if(irqNum < NUM_IRQS)
  {
    irq_callbacks[irqNum] = callback;
  }
  else
  {
    printf("IRQ INDEX OUT OF RANGE: %d!", irqNum);
  }
}
