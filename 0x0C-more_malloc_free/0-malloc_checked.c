#include "main.h"

/**
  * malloc_checked - Allocate memory using malloc.
  *
  * @b: Unsigned int parameter, the bytes to allocate.
  *
  * Return: Nothing.
  */

void *malloc_checked(unsigned int b)
{
	void *allocate;

	allocate = malloc(b);
	if (allocate == NULL)
		exit(98);
	else
		return (allocate);
}
