#include "main.h"

/**
  * cap_string - Capitalize all words of a string.
  *
  * @s : String parameter.
  *
  * Return: Uppercase string.
  */

char *cap_string(char *s)
{
	int capitalizeNext = 1;

	while (*s != '\0')
	{
		if ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z'))
		{
			if (capitalizeNext)
			{
				if (*s >= 'a' && *s <= 'z')
				{
					*s = *s - 'a' + 'A';
				}
				capitalizeNext = 0;
			}
		}
		else
		{
			capitalizeNext = 1;
		}
		s++;
	}

	return s;
}
