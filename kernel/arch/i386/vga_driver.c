#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

#include <kernel/vga_driver.h>

static volatile uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;

static unsigned char terminalRow = 0;
static unsigned char terminalColumn = 0;

void terminal_putchar(char c, char foregroundColor, char backgroundColor)
{
	switch(c)
	{
		case '\n': //if the char is the newline character
			terminalColumn = 0;
			terminalRow++;
			break;
		default: //if the char is a regular char
			/* Writes the char to the vga memory address */
			VGA_MEMORY[(VGA_COLS * terminalRow) + terminalColumn] = ((backgroundColor & 0x0F) << 12) |
			 ((foregroundColor & 0x0F) << 8) | (c & 0xFF);
			terminalColumn++;
			break;
	}
	/* Moves the cursor */
	if(terminalColumn >= VGA_COLS)
	{
		terminalColumn = 0;
		terminalRow++;
	}
	if(terminalRow >= VGA_ROWS)
	{
		//TODO: Scroll the screen
		terminalColumn = 0;
		terminalRow = 0;
	}
}

void terminal_putchar_default(char c)
{
	switch(c)
	{
		case '\n': //if the char is the newline character
			terminalColumn = 0;
			terminalRow++;
			break;
		default: //if the char is a regular char
			/* Writes the char to the vga memory address */
			VGA_MEMORY[(VGA_COLS * terminalRow) + terminalColumn] = ((VGA_COLOR_BLACK & 0x0F) << 12) |
			 ((VGA_COLOR_LIGHT_GREY & 0x0F) << 8) | (c & 0xFF);
			terminalColumn++;
			break;
	}
	/* Moves the cursor */
	if(terminalColumn >= VGA_COLS)
	{
		terminalColumn = 0;
		terminalRow++;
	}
	if(terminalRow >= VGA_ROWS)
	{
		//TODO: Scroll the screen
		terminalColumn = 0;
		terminalRow = 0;
	}
}

void terminal_printstring(const char* const str)
{
	const char* i = str;
	while(*i)
	{
		terminal_putchar_default(*i);
		i++;
	}
}

void terminal_print(const char* const arr, unsigned int size)
{
	for(unsigned int i = 0; i < size; i++)
	{
		terminal_putchar_default(arr[i]);
	}
}
