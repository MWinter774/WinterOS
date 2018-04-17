#include <stdio.h>
#include <limits.h>
#include <kernel/init_gdt.h>
#include <kernel/init_idt.h>
#include <kernel/init_pic.h>
#include <kernel/isr.h>

void tick()
{
	static unsigned int time = 0;
	time += 55;
	if(time % 1045 == 0)
	{
		printf("1 sec passed!\n");
	}
}

void kmain()
{
	kernel_init_gdt();
	kernel_init_idt();
	kernel_init_pic();
	register_irq_callback(0, &tick);

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

	while(1);
}
