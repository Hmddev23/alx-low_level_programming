#include "main.h"

/**
  * leet - Encode a string into 1337.
  *
  * @s: String parameter.
  *
  * Return: String.
  */

char *leet(char *s)
{
	int s_len, leet_len;

	char *letters = "aAeEoOtTlL";
	char *numbers = "4433007711";

	for (s_len = 0; s[s_len] != '\0'; s_len++)
	{
		for (leet_len = 0; leet_len < 10; leet_len++)
		{
			if (s[s_len] == a[leet_len])
			{
				s[s_len] = b[leet_len];
			}
		}
	}

	return (s);
}
