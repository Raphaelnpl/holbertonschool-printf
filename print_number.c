#include "main.h"
#include <unistd.h>

/**
 * print_number - Prints an integer as a string.
 * @num: The integer to print.
 *
 * Return: The number of characters printed.
 */
int print_number(int num)
{
	int count = 0;
	int temp;
	int divisor = 1;
	char digit;

	if (num < 0)
	{
		num = -num;
		count += write(1, "-", 1);
	}

	temp = num;
	while (temp / 10 > 0)
	{
		temp /= 10;
		divisor *= 10;
	}

	while (divisor > 0)
	{
		digit = (num / divisor % 10) + '0';
		count += write(1, &digit, 1);
		divisor /= 10;
	}

	return count;
}
