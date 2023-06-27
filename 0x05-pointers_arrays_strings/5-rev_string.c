#include "main.h"

/**
 * rev_string - reverses a string.
 *
 * @s: String parameter to be reversed.
 *
 * return: Nothing.
 */

void rev_string(char *s)
{
	int length, start, end;

	start = 0;

	while (s[length] != '\0')
	{
		length++;
	}

	end = length - 1;

	while (start < end)
	{
		char temp = s[start];

		s[start] = s[end];
		s[end] = temp;

		start++;
		end--;
	}
}