#include "main.h"

/**
 * _printf - Custom implementation of printf function.
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	const char *ptr;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	for (ptr = format; *ptr; ptr++)
	{
		if (*ptr == '%' && (*(ptr + 1) != '\0'))
		{
			ptr++;
			printed_chars += handle_specifier(*ptr, args);
		}
		else
		{
			write(1, ptr, 1);
			printed_chars++;
		}
	}
	va_end(args);
	return (printed_chars);
}
