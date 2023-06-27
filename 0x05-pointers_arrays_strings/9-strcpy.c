#include "main.h"

/**
 * *_strcpy - Copie the string pointed to by src.
 *
 * @dest: Pointer to the buffer in which we copy the string
 * @src: String to be copied.
 *
 * Return: The pointer to dest.
 */

char *_strcpy(char *dest, char *src)
{
	int length, i;

	length = 0;

	while (src[length] != '\0')
	{
		length++;
	}

	for (i = 0; i < length; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}
