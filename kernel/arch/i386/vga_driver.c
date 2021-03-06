#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

#include <kernel/vga_driver.h>
#include <kernel/assembly_wrapper.h>

/* The I/O ports */
#define FB_COMMAND_PORT         0x3D4
#define FB_DATA_PORT            0x3D5

/* The I/O port commands */
#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND     15

static volatile uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;

static const int VGA_SCREEN_SIZE = VGA_COLS * VGA_ROWS;
static unsigned short cursorPos = 0;

void terminal_update_cursor()
{
	outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
	outb(FB_DATA_PORT, ((cursorPos >> 8) & 0x00FF));
	outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
	outb(FB_DATA_PORT, cursorPos & 0x00FF);
}

void terminal_putchar(char c, char foregroundColor, char backgroundColor, bool updateCursor)
{
	switch(c)
	{
		case '\n': //if the char is the newline character
			cursorPos = ((int)((cursorPos + 80) / 80)) * 80;
			break;
		default: //if the char is a regular char
			/* Writes the char to the vga memory address */
			VGA_MEMORY[cursorPos] = ((backgroundColor & 0x0F) << 12) | ((foregroundColor & 0x0F) << 8) | (c & 0xFF);
			cursorPos++;
			break;
	}

	if(cursorPos >= VGA_SCREEN_SIZE)
	{
		//TODO: Scroll the screen
		terminal_scroll();
	}

	if(updateCursor)
	{
		terminal_update_cursor();
	}
}

void terminal_putchar_default(char c, bool updateCursor)
{
	switch(c)
	{
		case '\n': //if the char is the newline character
			cursorPos = ((int)((cursorPos + VGA_COLS) / VGA_COLS)) * VGA_COLS;
			break;
		default: //if the char is a regular char
			/* Writes the char to the vga memory address */
			VGA_MEMORY[cursorPos] = ((VGA_COLOR_BLACK & 0x0F) << 12) | ((VGA_COLOR_LIGHT_GREY & 0x0F) << 8) | (c & 0xFF);
			cursorPos++;
			break;
	}

	if(cursorPos >= VGA_SCREEN_SIZE)
	{
		//TODO: Scroll the screen
		terminal_scroll();
	}

	if(updateCursor)
	{
		terminal_update_cursor();
	}
}

void terminal_printstring(const char* const str)
{
	const char* i = str;
	while(*i)
	{
		terminal_putchar_default(*i, false);
		i++;
	}
	terminal_update_cursor();
}

void terminal_print(const char* const arr, unsigned int size)
{
	for(unsigned int i = 0; i < size; i++)
	{
		terminal_putchar_default(arr[i], false);
	}
	terminal_update_cursor();
}

void terminal_set_cursor_position(unsigned short pos)
{
	cursorPos = pos;
	terminal_update_cursor();
}

void terminal_scroll()
{
	/* Bring up each line by 1 line */
	for(unsigned int i = 1; i < VGA_ROWS; i++)
	{
		for(unsigned int j = 0; j < VGA_COLS; j++)
		{
			VGA_MEMORY[((i - 1) * VGA_COLS) + j] = VGA_MEMORY[(i * VGA_COLS) + j];
		}
	}
	VGA_MEMORY[(VGA_ROWS - 1) * VGA_COLS] = ((VGA_COLOR_BLACK & 0x0F) << 12) | ((VGA_COLOR_LIGHT_GREY & 0x0F) << 8);
	cursorPos = (VGA_ROWS - 1) * VGA_COLS;
}
