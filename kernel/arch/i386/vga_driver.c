#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <kernel/vga_driver.h>

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;

static size_t terminal_row = 0;
static size_t terminal_column = 0;
static uint8_t terminal_color = 0;
static uint16_t* terminal_buffer;

void terminal_putchar(unsigned int i, char c, char foregroundColor, char backgroundColor)
{
	VGA_MEMORY[i] = ((backgroundColor & 0x0F) << 12) | ((foregroundColor & 0x0F) << 8) | (c & 0xFF);
}
