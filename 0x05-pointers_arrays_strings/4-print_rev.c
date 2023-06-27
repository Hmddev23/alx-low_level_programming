#include "main.h"

/**
 * print_rev - prints a string in reverse, followed by a new line.
 *
 * @s: String parameter to be printed.
 *
 * return: Nothing.
 */

void print_rev(char *s)
{
	int ctr, length;

	length = 0;

	while (s[length] != '\0')
	{
		length++;
	}

	for (ctr = length - 1; ctr >= 0; ctr--)
	{
		_putchar(s[ctr]);
	}
	_putchar('\n');
}
