#include "main.h"

/**
 * _strlen - Calculates the length of a string.
 * @s: The string to measure.
 *
 * Return: The length of the string.
 */
int _strlen(const char *s)
{
	int length = 0;

	while (s[length])
	{
		length++;
	}

	return length;
}
