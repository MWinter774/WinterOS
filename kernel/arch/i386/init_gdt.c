#include <kernel/init_gdt.h>
#include <stdio.h> //DEBUG

extern void load_gdt(unsigned int);

static gdt_entry_t gdt_set_gate(unsigned int base, unsigned int limit, unsigned char access, unsigned char granularity)
{
  gdt_entry_t gdt_entry;
  gdt_entry.base_low = (base&0xFFFF);
	gdt_entry.base_middle = (base>>16)&0xFF;
	gdt_entry.base_high = (base>>24)&0xFF;
	gdt_entry.limit_low = (limit&0xFFFF);
	gdt_entry.granularity = (limit>>16)&0x0F;
	gdt_entry.granularity |= granularity&0xF0;
	gdt_entry.access=access;
  return gdt_entry;
}

gdt_entry_t gdt_entries[5];

void kernel_init_gdt()
{
	gdt_ptr_t gdt_ptr;
	gdt_ptr.limit = (sizeof(gdt_entry_t) * 5) - 1;
	gdt_ptr.base  = (unsigned int)&gdt_entries;
  gdt_entries[0] = gdt_set_gate(0, 0, 0, 0);
  gdt_entries[1] = gdt_set_gate(0, 0xFFFFFFFF, 0x9A, 0xCF);
  gdt_entries[2] = gdt_set_gate(0, 0xFFFFFFFF, 0x92, 0xCF);
  gdt_entries[3] = gdt_set_gate(0, 0xFFFFFFFF, 0xFA, 0xCF);
  gdt_entries[4] = gdt_set_gate(0, 0xFFFFFFFF, 0xF2, 0xCF);
	load_gdt((unsigned int)&gdt_ptr);
}
