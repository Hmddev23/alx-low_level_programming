#include "main.h"

/**
  * _strcat - Concatenate two strings.
  *
  * @dest: String that will be appended.
  * @src: String to be concatenated upon.
  *
  * Return: Return poiner to @dest.
  */

char *_strcat(char *dest, char *src)
{

	int i;
	int dest_length;

	i = 0;
	dest_length = 0;

	while (dest[i++])
	{
		dest_length++;
	}

	for (i = 0; src[i]; i++)
	{
		dest[dest_length++] = src[i];
	}

	return (dest);
}
