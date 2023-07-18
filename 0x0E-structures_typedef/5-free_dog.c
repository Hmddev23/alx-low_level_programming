#include "dog.h"

/**
  * free_dog - Free the allocated memory for a dog structure.
  *
  * @d: Pointer to the dog structure.
  *
  * Return: Nothing.
  */

void free_dog(dog_t *d)
{
	if (d == NULL)
	{
		return;
	}

	free(d->name);
	free(d->owner);
	free(d);
}
