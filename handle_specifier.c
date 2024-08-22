#include "main.h"

/**
 * handle_specifier - Handles format specifiers.
 * @specifier: The format specifier.
 * @args: The argument list.
 *
 * Return: The number of characters printed.
 */
int handle_specifier(char specifier, va_list args)
{
	int count = 0;
	char c;
	char *str;

	switch (specifier)
	{
		case 'c':
			c = (char)va_arg(args, int);
			write(1, &c, 1);
			count++;
			break;
		case 's':
			str = va_arg(args, char *);
			if (str == NULL)
				str = "(null)";
			count += _strlen(str);
			write(1, str, _strlen(str));
			break;
		case '%':
			write(1, "%", 1);
			count++;
			break;
		default:
			write(1, "%", 1);
			write(1, &specifier, 1);
			count += 2;
			break;
	}
	return (count);
}
