#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * handle_specifier - Handles a format specifier and prints the corresponding output.
 * @format: The format specifier.
 * @args: The list of arguments.
 * Return: The number of characters printed.
 */
int handle_specifier(const char *format, va_list args)
{
	int count = 0;

	if (*format == 'c')
	{
		char c = va_arg(args, int);
		count += write(1, &c, 1);
	}
	else if (*format == 's')
	{
		char *str = va_arg(args, char *);
		while (*str)
		{
			count += write(1, str++, 1);
		}
	}
	return count;
}
