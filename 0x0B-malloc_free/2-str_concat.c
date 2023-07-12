#include "main.h"

/**
  * str_concat - Concatenate two strings.
  *
  * @s1: Char poinetr parameter.
  * @s2: Char pointer parameter.
  *
  * Return: String contains the contents of s1 and s2.
  */

char *str_concat(char *s1, char *s2)
{
	int len1,len2;
	char *p, *result;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	len1 = 0;
	len2 = 0;
	p = s1;
	while (*p != '\0')
	{
		len1++;
		p++;
	}
	p = s2;
	while (*p != '\0')
	{
		len2++;
		p++;
	}
	result = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	p = s1;
	while (*p != '\0')
	{
		*result = *p;
		result++;
		p++;
	}
	p = s2;
	while (*p != '\0')
	{
		*result = *p;
		result++;
		p++;
	}
	*result = '\0';
	return (result - (len1 + len2));
}
