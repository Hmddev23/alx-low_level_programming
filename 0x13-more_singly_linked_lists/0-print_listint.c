#include "lists.h"

/**
  * print_listint - Print all the elements of a linked list.
  *
  * @h: Pointer to the head of the list.
  *
  * Return: Number of nodes in the list.
  */

size_t print_listint(const listint_t *h)
{
	size_t count = 0;
	const listint_t *current = h;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
		count++;
	}

	return (count);
}
