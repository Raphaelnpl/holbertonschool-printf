#include "main.h"

/**
 * _printf - A simplified version of printf.
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *ptr;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == '\0')
			{
				write(1, "%", 1);
				count++;
				break;
			}
			else
			{
				count += handle_specifier(*ptr, args);
			}
		}
		else
		{
			write(1, ptr, 1);
			count++;
		}
	}

	va_end(args);
	return count;
}
