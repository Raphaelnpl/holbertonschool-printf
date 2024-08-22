#include "main.h"
/**
 * handle_specifier - Handles a format specifier in _printf.
 * @specifier: The format specifier character (e.g., 'c', 's', 'd', etc.).
 * @args: The list of arguments passed to _printf.
 *
 * Return: The number of characters printed.
 */

int handle_specifier(char specifier, va_list args)
{
	int count = 0;

	if (specifier == 'c')
	{
		char c = va_arg(args, int);
		count += write(1, &c, 1);
	}
	else if (specifier == 's')
	{
		char *str = va_arg(args, char *);
		count += write(1, str, _strlen(str));
	}
	else if (specifier == 'd' || specifier == 'i')
	{
		int num = va_arg(args, int);
		count += print_number(num);
	}

	return count;
}
