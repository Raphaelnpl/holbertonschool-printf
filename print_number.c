#include "main.h"

/**
 * print_number - Prints an integer.
 * @num: The integer to print.
 *
 * Return: The number of characters printed.
 */
int print_number(int num)
{
	int count = 0;
	char digit;

	if (num < 0)
	{
		write(1, "-", 1);
		count++;
		num = -num;
	}

	if (num / 10 != 0)
		count += print_number(num / 10);

	digit = (num % 10) + '0';
	write(1, &digit, 1);
	count++;

	return (count);
}
