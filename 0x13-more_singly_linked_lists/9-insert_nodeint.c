#include "lists.h"

/**
  * insert_nodeint_at_index - Insert a new node at a given position.
  *
  * @head: Double pointer to the head node.
  * @idx: Index where the new node should be added.
  * @n: Data of the new node.
  *
  * Return: Address of the new node or NULL if it fails.
  */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new_node;
	listint_t *h;

	h = *head;

	if (idx != 0)
	{
		for (i = 0; i < idx - 1 && h != NULL; i++)
		{
			h = h->next;
		}
	}

	if (h == NULL && idx != 0)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
	}
	else
	{
		new_node->next = h->next;
		h->next = new_node;
	}
	return (new_node);
}
