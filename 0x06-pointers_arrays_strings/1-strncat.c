#include "main.h"

/**
  * _strncat - Concatenate n bytes from a string to another.
  *
  * @dest: Destination string.
  * @src: Source string.
  * @n: Number of bytes of str to concatenate.
  *
  * Return: Pointer to the resulting string dest.
  */

char *_strncat(char *dest, char *src, int n)
{
	int dest_length, index;

	dest_length = 0;
	index = 0;

	while (dest[dest_length] != '\0')
	{
		dest_length++;
	}

	while (src[index] != '\0' && index < n)
	{
		dest[dest_length] = src[index];
		dest_length++;
		index++;
	}

	dest[dest_length] = '\0';

	return (dest);
}
