#include <string.h>
#include <stddef.h>
#include <kernel/vga_driver.h>

char* strrev(char* str)
{
  size_t len = strlen(str);
  char temp = 0;
  size_t first = 0;
  size_t end = len - 1;

  for(size_t i = 0; i < len / 2; i++)
  {
    temp = str[first];
    str[first] = str[end];
    str[end] = temp;
    first++;
    end--;
  }

  return str;
}
