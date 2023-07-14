#include "main.h"

/**
  * _calloc - Allocate memory for an array, using malloc.
  *
  * @nmemb: Unsigned int parameter input size 1.
  * @size: Unsigned int parameter, the size..
  *
  * Return: Nothing.
  */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int totalSize;

	if (nmemb == 0 || size == 0)
		return (NULL);

	totalSize = nmemb * size;

	ptr = malloc(totalSize);
	if (ptr == NULL)
		return (NULL);

	memset(ptr, 0, totalSize);

	return (ptr);
}
