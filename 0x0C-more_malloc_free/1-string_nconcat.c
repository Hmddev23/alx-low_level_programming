#include "main.h"

/**
  * string_nconcat - Concatenate two strings.
  *
  * @s1: String parameter.
  * @s2: String parameter.
  * @n: Number of bytes from s2.
  *
  * Return: Pointer to the newly allocated string.
  */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *result;
	unsigned int len1, len2, totalLen, i, j;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	len1 = 0;
	len2 = 0;
	while (s1[len1] != '\0')
		len1++;

	while (s2[len2] != '\0')
		len2++;

	if (n >= len2)
		n = len2;

	totalLen = len1 + n;

	result = (char *)malloc((totalLen + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		result[i] = s1[i];

	for (j = 0; j < n; j++)
		result[len1 + j] = s2[j];

	result[totalLen] = '\0';

	return (result);
}
