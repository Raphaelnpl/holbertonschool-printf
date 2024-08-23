#include "main.h"

/**
 * print_number - Prints an integer to stdout.
 * @n: The integer to print.
 *
 * Return: The number of characters printed.
 */
int print_number(int n)
{
	unsigned int num;
	int count = 0;
	char digit;

	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		num = (unsigned int)(-n);
	}
	else
	{
		num = (unsigned int)n;
	}

	if (num / 10)
		count += print_number(num / 10);

	digit = (num % 10) + '0';
	write(1, &digit, 1);
	count++;

	return count;
}

