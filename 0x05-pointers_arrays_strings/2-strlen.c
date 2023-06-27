#include "main.h"

/**
 * _strlen - Returns the length of a string.
 * 
 * @s: String to count its length.
 *
 * Return: Length of the string.
 */
int _strlen(char *s)
{
	int length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}

	return (length);
}
