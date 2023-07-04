#include "main.h"

/**
  * _strchr - Get the length of a prefix substring.
  *
  * @s: String to search.
  * @c: Char to find.
  *
  * Return: Number of bytes in the initial segment of s.
  */

char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}

	return (NULL);
}
