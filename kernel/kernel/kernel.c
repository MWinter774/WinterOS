#include <stdio.h>
#include <limits.h>
#include <kernel/init_gdt.h>
#include <kernel/init_idt.h>

void kmain()
{
	kernel_init_gdt();
	kernel_init_idt();
	printf("Hello, kernel World!\n");
	printf("Some tests:\n");
	printf("\"HI I AM A STRING!\" = %s\n", "\"HI I AM A STRING!\"");
	printf("1 + 2 = %d\n", 1 + 2);
	printf("5 * 8 = %i\n", 5 * 8);
	printf("-8 / 2 - 17 = %d\n", (-8/2 - 17));
	printf("INT_MAX = %d\n", INT_MAX);
	printf("INT_MIN = %d\n", INT_MAX * -1);
	printf("***Interrupt 0x80:***\n");
	__asm__("int $0x80");
	printf("***Interrupt 0x0A:***\n");
	__asm__("int $0x0A");
}
