#include "main.h"

/**
  * cap_string - Capitalize all words of a string.
  *
  * @s : String parameter.
  *
  * Return: Uppercase string.
  */

char *cap_string(char *str)
{
	int capitalizeNext = 1;

	while (*str != '\0')
	{
		if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
		{
			if (capitalizeNext)
			{
				if (*str >= 'a' && *str <= 'z')
				{
					*str = *str - 'a' + 'A';
				}
				capitalizeNext = 0;
			}
		}
		else
		{
			capitalizeNext = 1;
		}
		str++;
	}

	return str;
}
