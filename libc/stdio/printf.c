#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <kernel/vga_driver.h>

static int k_putchar(int ic)
{
  char c = (char) ic;
  terminal_putchar_default(c, false);

  return ic;
}

static bool print(const char* data, size_t length)
{
	const unsigned char* bytes = (const unsigned char*) data;
	for (size_t i = 0; i < length; i++)
  {
		if (k_putchar(bytes[i]) == EOF)
    {
      terminal_update_cursor();
			return false;
    }
  }
  terminal_update_cursor();
  return true;
}

int printf(const char* format, ...)
{
  va_list parameters;
	va_start(parameters, format);

	int written = 0;

	while (*format != '\0')
  {
		size_t maxrem = INT_MAX - written;

		if (format[0] != '%' || format[1] == '%')
    {
			if (format[0] == '%')
				format++;
			size_t amount = 1;
			while (format[amount] && format[amount] != '%')
				amount++;
			if (maxrem < amount)
      {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(format, amount))
				return -1;
			format += amount;
			written += amount;
			continue;
		}

		const char* format_begun_at = format++;

		if (*format == 'c')
    {
			format++;
			char c = (char) va_arg(parameters, int /* char promotes to int */);
			if (!maxrem)
      {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(&c, sizeof(c)))
				return -1;
			written++;
		}
    else if (*format == 's')
    {
			format++;
			const char* str = va_arg(parameters, const char*);
			size_t len = strlen(str);
			if (maxrem < len)
      {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(str, len))
				return -1;
			written += len;
		}
    else if(*format == 'd' || *format == 'i')
    {
      format++;
      int originalNum = (int) va_arg(parameters, int); //converts argument to int
      int num = originalNum > 0 ? originalNum : originalNum * -1;
      char str[12] = { 0 }; //maximum number of digits for int number, including the minus sign(-)
      size_t i = 0;

      do
      {
        str[i++] = (num % 10) + '0';
        num /= 10;
      } while(num != 0);
      
      if(originalNum < 0)
      {
        str[i++] = '-';
      }
      strrev(str);
      if(!print(str, i))
      {
        return -1;
      }
      terminal_update_cursor();
    }
    else
    {
      format = format_begun_at;
			size_t len = strlen(format);
			if (maxrem < len)
      {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(format, len))
				return -1;
			written += len;
			format += len;
		}
	}

  va_end(parameters);
	return written;
}
