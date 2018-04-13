#include <stdio.h>
#include <kernel/vga_driver.h>

int putchar(int ic)
{
  char c = (char) ic;
  terminal_putchar_default(c, true);

  return ic;
}
