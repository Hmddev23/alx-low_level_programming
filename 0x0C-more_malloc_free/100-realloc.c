#include "main.h"

/**
  * _realloc - Reallocate a memory block using malloc and free.
  *
  * @ptr: Void pointer to the previously allocated memory.
  * @old_size: Unsigned int parameter, old size in bytes.
  * @new_size: Unsigned int parameter, new size in bytes.
  *
  * Return: Pointer to the newly allocated memory block.
  */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	unsigned char *src, *dest;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	src = (unsigned char *)ptr;
	dest = (unsigned char *)new_ptr;

	for (i = 0; i < old_size && i < new_size; i++)
		dest[i] = src[i];

	free(ptr);

	return (new_ptr);
}
