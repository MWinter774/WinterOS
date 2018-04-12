#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

#include <kernel/vga_driver.h>

static volatile uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;

static unsigned char terminal_row = 0;
static unsigned char terminal_column = 0;

void terminal_putchar(char c, char foregroundColor, char backgroundColor)
{
	/* Writes the char to the vga memory address */
	VGA_MEMORY[(VGA_ROWS * terminal_row) + terminal_column] = ((backgroundColor & 0x0F) << 12) |
	 ((foregroundColor & 0x0F) << 8) | (c & 0xFF);

	 /* Moves the cursor */
	 if(++terminal_column >= VGA_COLS)
	 {
		 terminal_column = 0;
		 if(++terminal_row >= VGA_ROWS)
		 {
			 terminal_row = 0;
		 }
	 }
}

void terminal_putchar_default(char c)
{
	/* Writes the char to the vga memory address */
	VGA_MEMORY[(VGA_COLS * terminal_row) + terminal_column] = ((VGA_COLOR_BLACK & 0x0F) << 12) |
	 ((VGA_COLOR_LIGHT_GREY & 0x0F) << 8) | (c & 0xFF);

	 /* Moves the cursor */
	 terminal_column++;
	 if(terminal_column >= VGA_COLS)
	 {
		 terminal_column = 0;
		 terminal_row++;
		 if(terminal_row >= VGA_ROWS)
		 {
			 terminal_row = 0;
		 }
	 }
}
