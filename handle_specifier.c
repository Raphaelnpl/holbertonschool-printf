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
	int num;
	char buffer[12];
	int len;
	int temp;

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
		case 'd':
		case 'i':
			num = va_arg(args, int);
			if (num < 0)
			{
				write(1, "-", 1);
				count++;
				num = -num;
			}
			len = 0;
			temp = num;
			do {
				buffer[len++] = (temp % 10) + '0';
				temp /= 10;
			} while (temp > 0);

			while (len > 0)
				write(1, &buffer[--len], 1);

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
