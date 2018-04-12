#ifndef _KERNEL_FRAME_BUFFER_H
#define _KERNEL_FRAME_BUFFER_H
#include <stdbool.h>
#define VGA_COLS 80
#define VGA_ROWS 25

enum vga_color
{
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};

/*
Writes a char to the screen.
Input:
c - the char to write to the screen
foregroundColor - the color of the char(see vga_color enum for available colors)
backgroundColor - the color of the background of the char(see vga_color enum for available colors)
Output:
*/
void terminal_putchar(char c, char foregroundColor, char backgroundColor, bool updateCursor);

/*
Writes a char to the screen, with the default colors(foreground=light gray, background=black).
Input:
c - the char to write to the screen
Output:
*/
void terminal_putchar_default(char c, bool updateCursor);

/*
Prints a null terminated string to the screen.
Input:
str - the string to print
Output:
*/
void terminal_printstring(const char* const str);

/*
Prints an array of chars to the screen.
Input:
str - the array to print
size - the size of the array
Output:
*/
void terminal_print(const char* const arr, unsigned int size);

/*
Sets a new cursor position.
Input:
pos - the new position of the cursor
Output:
*/
void terminal_set_cursor_position(unsigned short pos);

/*
Scrolls down the terminal.
Input:
Output:
*/
void terminal_scroll();

#endif
