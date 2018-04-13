#include <stdio.h>
#include <limits.h>

void kmain()
{
	printf("Hello, kernel World!\n");
	printf("Some tests:\n");
	printf("\"HI I AM A STRING!\" = %s\n", "\"HI I AM A STRING!\"");
	printf("1 + 2 = %d\n", 1 + 2);
	printf("5 * 8 = %i\n", 5 * 8);
	printf("-8 / 2 - 17 = %d\n", (-8/2 - 17));
	printf("INT_MAX = %d\n", INT_MAX);
	printf("INT_MIN = %d\n", INT_MAX * -1);
}
