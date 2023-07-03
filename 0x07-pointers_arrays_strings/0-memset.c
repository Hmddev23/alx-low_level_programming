#include "main.h"

/**
  * _memset - Fill memory with a constant byte.
  *
  * @s: memory area to be filled.
  * @b: Constant byte.
  * @n: Bytes of the memory area.
  *
  * Return: Pointer to the memory area.
  */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int index;

	for (index = 0; index < n; index++)
	{
		s[index] = b;
	}
	return (s);
}
