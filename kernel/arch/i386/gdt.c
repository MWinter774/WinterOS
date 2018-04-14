#include <kernel/gdt.h>

extern void load_gdt(unsigned int);

static void gdt_set_gate(gdt_entry_t* gdtEntry, unsigned int base, unsigned int limit, unsigned char access,
  unsigned char granularity)
{
	gdtEntry->base_low = (base&0xFFFF);
	gdtEntry->base_middle = (base>>16)&0xFF;
	gdtEntry->base_high = (base>>24)&0xFF;
	gdtEntry->limit_low = (limit&0xFFFF);
	gdtEntry->granularity = (limit>>16)&0x0F;
	gdtEntry->granularity |= granularity&0xF0;
	gdtEntry->access=access;
}

void kernel_init_gdt()
{
  gdt_entry_t gdt_entries[5];
	gdt_ptr_t gdt_ptr;
	gdt_ptr.limit = (sizeof(gdt_entry_t) * 5) - 1;
	gdt_ptr.base  = (unsigned int)&gdt_entries;
	gdt_set_gate(&gdt_entries[0], 0, 0, 0, 0);
	gdt_set_gate(&gdt_entries[1], 0, 0xFFFFFFFF, 0x9A, 0xCF);
	gdt_set_gate(&gdt_entries[2], 0, 0xFFFFFFFF, 0x92, 0xCF);
	gdt_set_gate(&gdt_entries[3], 0, 0xFFFFFFFF, 0xFA, 0xCF);
	gdt_set_gate(&gdt_entries[4], 0, 0xFFFFFFFF, 0xF2, 0xCF);
	load_gdt((unsigned int)&gdt_ptr);
}
