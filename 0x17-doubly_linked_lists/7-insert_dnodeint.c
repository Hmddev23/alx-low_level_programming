#include "lists.h"

/**
  * dlistint_len - Get the length of a double linked list.
  *
  * @h: Pointer to the head.
  *
  * Return: Size of the doubly linked list.
  */

size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *current = h;
	size_t len = 0;

	while (current != NULL)
	{
		current = current->next;
		len++;
	}

	return (len);
}

/**
  * insert_dnodeint_at_index - Insert node at given index.
  *
  * @h: Pointer to the head.
  * @idx: Index parameter.
  * @n: Value of the new node.
  *
  * Return: Pointer the newly created node.
  */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *n_node;
	dlistint_t *current, *next;

	if (h == NULL || idx > dlistint_len(*h))
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	if (idx == dlistint_len(*h))
		return (add_dnodeint_end(h, n));

	current = *h;
	while (idx > 1)
	{
		current = current->next;
		idx--;
	}

	next = current->next;

	n_node = malloc(sizeof(dlistint_t));
	if (n_node == NULL)
		return (NULL);

	n_node->n = n;
	n_node->prev = current;
	n_node->next = next;
	current->next = n_node;
	next->prev = n_node;

	return (n_node);
}
