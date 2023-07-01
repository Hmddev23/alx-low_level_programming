#include "main.h"

/**
  * _strcmp - Compare two strings.
  *
  * @s1: First string parameter.
  * @s2: Second string parameter.
  *
  * Return: index of change.
  */

int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}

		s1++;
		s2++;
	}

	return (*s1 - *s2);
}
