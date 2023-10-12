#include "lists.h"

/**
  * print_dlistint - Print the elements of a doubly linked list.
  *
  * @h: Pointer parameter to the list head.
  *
  * Return: The number of nodes in the list.
  */

size_t print_dlistint(const dlistint_t *h)
{
	size_t size = 0;

	while (h)
	{
		size++;
		printf("%d\n", h->n);
		h = h->next;
	}

	return (size);
}
