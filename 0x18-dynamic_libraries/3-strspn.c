#include "main.h"

/**
  * _strspn - Get the length of a prefix substring.
  *
  * @s: String to evalute.
  * @accept: String containing the list of charchters to match in s.
  *
  * Return: Number of bytes in the initial segment of s.
  */

unsigned int _strspn(char *s, char *accept)
{
	int length, match;
	char *a;

	length = 0;

	while (*s)
	{
		match = 0;
		a = accept;

		while (*a)
		{
			if (*s == *a)
			{
				match = 1;
				break;
			}
			a++;
		}
		if (!match)
		{
			break;
		}
		length++;
		s++;
	}

	return (length);
}
