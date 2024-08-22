#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * handle_specifier - Handles a format specifier and prints the corresponding output.
 * @format: The format specifier.
 * @args: The list of arguments.
 * 
 * Return: The number of characters printed.
 */
int handle_specifier(const char *format, va_list args)
{
	int count = 0;

	switch (*format)
	{
		case 'c':
			{
				char c = va_arg(args, int);
				count += write(1, &c, 1);
				break;
			}
		case 's':
			{
				char *str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				while (*str)
				{
					count += write(1, str++, 1);
				}
				break;
			}
		case '%':
			{
				count += write(1, "%", 1);
				break;
			}
		case 'd':
		case 'i':
			{
				int num = va_arg(args, int);
				count += print_number(num);
				break;
			}
		default:
			{
				count += write(1, "%", 1);
				count += write(1, format, 1);
				break;
			}
	}

	return count;
}

/**
 * print_number - Prints an integer number.
 * @n: The integer to be printed.
 * 
 * Return: The number of characters printed.
 */
int print_number(int n)
{
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		count += write(1, "-", 1);
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
	{
		count += print_number(num / 10);
	}

	char digit = (num % 10) + '0';
	count += write(1, &digit, 1);

	return count;
}
