#include "lists.h"

/**
  * listint_len - Get the number of elements.
  *
  * @h: Pointer to the first node.
  *
  * Return: Number of elements.
  */

size_t listint_len(const listint_t *h)
{
	size_t count = 0;
	const listint_t *current = h;

	if (h == NULL)
		return (0);

	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	return (count);
}
