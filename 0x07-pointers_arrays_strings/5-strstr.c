#include "main.h"

/**
  * _strstr - Locate a substring.
  *
  * @haystack: String parameter.
  * @needle: Substring parameter.
  * 
  * Return: Pointer to the beginning of the located substring.
  */

char *_strstr(char *haystack, char *needle)
{
	if (*needle == '\0')
	{
		return (haystack);
	}

	while (*haystack != '\0')
	{
		char *f = haystack;
		char *s = needle;

		while (*f == *s && *s != '\0')
		{
			f++;
			s++;
		}

		if (*s == '\0')
		{
			return (haystack);
		}
		haystack++;
	}

	return ('\0');
}
