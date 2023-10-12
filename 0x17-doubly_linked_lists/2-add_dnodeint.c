#include "lists.h"

/**
  * add_dnodeint - Add a new node at the beginning of a doubly linked list.
  *
  * @head: Double pointer to the head of the list.
  * @n: Int parameter as the new node value.
  *
  * Return: Address of the new node.
  */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new = malloc(sizeof(dlistint_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;

	return (*head);
}
