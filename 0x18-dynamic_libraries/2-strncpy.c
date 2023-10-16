#include "main.h"

/**
  * _strncpy - Copy a string.
  *
  * @dest: Destination string.
  * @src: Source string.
  * @n: Number of bytes to copy.
  *
  * Return: Pointer to the resulting string.
  */

char *_strncpy(char *dest, char *src, int n)
{
	int index = 0;

	while (src[index] && index < n)
	{
		dest[index] = src[index];
		index++;
	}

	while (index < n)
	{
		dest[index] = '\0';
		index++;
	}

	return (dest);
}
