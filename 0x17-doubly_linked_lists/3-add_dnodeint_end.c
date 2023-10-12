#include "lists.h"

/**
  * add_dnodeint_end - Add a new node at the end of a dll.
  *
  * @head: head of the list.
  * @n: Value of the node.
  *
  * Return: Address of the new node.
  */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *h = *head;
	dlistint_t *new = malloc(sizeof(dlistint_t));

	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}
	while (h->next != NULL)
		h = h->next;

	h->next = new;
	new->prev = h;
	return (*head);
}
