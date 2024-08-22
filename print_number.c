#include "main.h"

/**
 * print_number - Prints an integer to stdout.
 * @num: The integer to print.
 *
 * Return: The number of characters printed.
 */
int print_number(int num)
{
	int count = 0;
	int divisor = 1;
	int temp;

	if (num < 0)
	{
		write(1, "-", 1);
		count++;
		num = -num;
	}

	temp = num;
	while (temp / divisor >= 10)
		divisor *= 10;

	while (divisor > 0)
	{
		char digit = (num / divisor % 10) + '0';
		write(1, &digit, 1);
		count++;
		divisor /= 10;
	}

	return count;
}
