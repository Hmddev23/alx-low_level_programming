#include "lists.h"

/**
  * get_dnodeint_at_index - Return the node at a given index in a dll.
  *
  * @head: Pointer to the head of the dll.
  * @index: Index of the node.
  *
  * Return: Pointer to the node at the specified index.
  */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int len = 0;
	dlistint_t *h = head;

	while (h)
	{
		len++;
		h = h->next;
	}
	if (index >= len || head == NULL)
		return (NULL);
	h = head;

	while (h && index != 0)
	{
		h = h->next;
		index--;
	}
	return (h);
}
