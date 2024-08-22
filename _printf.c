#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function.
 * @format: The format string.
 * @...: The arguments to format.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	const char *ptr = format;

	va_start(args, format);

	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == '\0')
			{
				break;
			}
			if (*ptr == '%')
			{
				write(1, "%", 1);
				printed_chars++;
			}
			else
			{
				printed_chars += write(1, "%", 1);
				printed_chars += write(1, ptr, 1);
			}
		}
		else
		{
			write(1, ptr, 1);
			printed_chars++;
		}
		ptr++;
	}

	va_end(args);
	return printed_chars;
}
