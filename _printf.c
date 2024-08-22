#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function.
 * @format: The format string.
 * @...: The values to format and print.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	const char *p = format;

	va_start(args, format);

	while (*p)
	{
		if (*p == '%')
		{
			p++;
			if (*p)
			{
				count += handle_specifier(*p, args);
			}
		}
		else
		{
			count += write(1, p, 1);
		}
		p++;
	}

	va_end(args);
	return count;
}
