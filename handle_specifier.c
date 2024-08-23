#include "main.h"
#include <limits.h>

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
	char c, *str;
	int num;
	int len = 0;

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
			write(1, str, _strlen(str));
			count += _strlen(str);
			break;
		case '%':
			write(1, "%", 1);
			count++;
			break;
		case 'd':
		case 'i':
			num = va_arg(args, int);
			len = print_number(num);
			count += len;
			break;
		default:
			write(1, "%", 1);
			write(1, &specifier, 1);
			count += 2;
			break;
	}
	return count;
}
