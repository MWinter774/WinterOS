#include <kernel/vga_driver.h>

void kmain()
{
	/*terminal_putchar(0, 'H', 1, 13);
	terminal_putchar(1, 'e', 2, 12);
	terminal_putchar(2, 'l', 3, 11);
	terminal_putchar(3, 'l', 4, 10);
	terminal_putchar(4, 'o', 5, 9);
	terminal_putchar(5, ' ', 6, 8);
	terminal_putchar(6, 'K', 14, 7);
	terminal_putchar(7, 'e', 8, 6);
	terminal_putchar(8, 'r', 9, 5);
	terminal_putchar(9, 'n', 10, 4);
	terminal_putchar(10, 'e', 11, 3);
	terminal_putchar(11, 'l', 12, 2);
	terminal_putchar(12, '!', 13, 1);*/
	int i = 0;
	int j = 0;
	char c = 'a';
	for(j = 0; j < 25; j++)
	{
		for(i=0; i < 80; i++)
		{
			terminal_putchar_default(c);
		}
		c++;
	}
	//printf("Hello, kernel World!\n");
}
