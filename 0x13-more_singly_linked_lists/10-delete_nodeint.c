#include "lists.h"

/**
  * delete_nodeint_at_index - Delete the node at a given position.
  *
  * @head: Double pointer to the head of the linked list.
  * @index: Index of the node to be deleted, starting at 0.
  *
  * Return: 1 if successful, -1 if it fails.
  */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current = *head;
	listint_t *prev = NULL;
	unsigned int i;

	if (*head == NULL)
	{
		return (-1);
	}

	if (index == 0)
	{
		listint_t *temp = *head;

		*head = (*head)->next;
		free(temp);
		return (1);
	}

	for (i = 0; i < index; i++)
	{
		if (current == NULL)
		{
			return (-1);
		}
		prev = current;
		current = current->next;
	}

	if (current == NULL)
	{
		return (-1);
	}

	prev->next = current->next;
	free(current);

	return (1);
}
