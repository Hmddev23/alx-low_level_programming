#include "main.h"

/**
 * puts2 - Print every other character of a string.
 *
 * @str: String parameter to print the chars from.
 *
 * return: Nothing.
 */

void puts2(char *str)
{
	int length, i;

	length = 0;

	while (str[length] != '\0')
	{
		length++;
	}

	for (i = 0; i < length; i += 2)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}
