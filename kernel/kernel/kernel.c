#include <kernel/vga_driver.h>

void kmain()
{
	// terminal_putchar('H', 1, 13);
	// terminal_putchar('e', 2, 12);
	// terminal_putchar('l', 3, 11);
	// terminal_putchar('l', 4, 10);
	// terminal_putchar('o', 5, 9);
	// terminal_putchar(' ', 6, 8);
	// terminal_putchar('K', 14, 7);
	// terminal_putchar('e', 8, 6);
	// terminal_putchar('r', 9, 5);
	// terminal_putchar('n', 10, 4);
	// terminal_putchar('e', 11, 3);
	// terminal_putchar('l', 12, 2);
	// terminal_putchar('!', 13, 1);
	unsigned long long i = 0;
	char c = 'A';
	char str[3] = { c, '\n', '\0' };
	while(true)
	{
		if(i % 9000000 == 0)
		{
			str[0] = c;
			terminal_printstring(str);
			c++;
		}
		i++;
	}
	//printf("Hello, kernel World!\n");
}
