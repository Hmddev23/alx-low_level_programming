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
	listint_t *new_node;
	unsigned int i;

	if (idx == 0) {
		return (add_nodeint(head, n));
	}

	new_node = (listint_t *)malloc(sizeof(listint_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->n = n;

	listint_t *current = *head;
	for (i = 0; i < idx - 1; i++)
	{
		if (current == NULL)
		{
			free(new_node);
			return (NULL);
		}
		current = current->next;
	}

	new_node->next = current->next;
	current->next = new_node;

	return (new_node);
}
