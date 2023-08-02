#include "lists.h"

/**
  * free_listint_safe - Free a listint_t list.
  *
  * @h: Pointer parameter to head node.
  *
  * Return: The size of the list that was free’d.
  */

size_t free_listint_safe(listint_t **h)
{
	listint_t *current = *h;
	listint_t *next;
	size_t size = 0;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
		size++;
	}

	*h = NULL;

	return (size);
}
