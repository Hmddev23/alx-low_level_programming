#include "main.h"

/**
  * wildcmp - Compare two strings.
  *
  * @s1: Pointer parameter to first string.
  * @s2: Pointer parameter to second string.
  *
  * Return: 1 if the strings identical, otherwise return 0.
  */

int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
	{
		return (1);
	}

	if (*s2 == '*')
	{
		return (wildcmp(s1, s2 + 1) || (*s1 != '\0' && wildcmp(s1 + 1, s2)));
	}

	if (*s1 == *s2)
	{
		return (wildcmp(s1 + 1, s2 + 1));
	}

	return (0);
}
