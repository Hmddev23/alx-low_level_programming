#include "main.h"

/**
  * rot13 - enoding rot13.
  *
  * @s: String parameter.
  *
  * Return: String.
  */

char *rot13(char *s)
{
	int i, j;

	char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char ROT13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; letters[j] != '\0'; j++)
		{
			if (s[i] == letters[j])
			{
				s[i] = ROT13[j];
				break;
			}
		}
	}
	return (s);
}
