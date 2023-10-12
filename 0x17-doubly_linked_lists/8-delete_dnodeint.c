#include "lists.h"

/**
  * delete_dnodeint_at_index - Delete a node at a given index in a dll.
  *
  * @head: Pointer parameter to the head of the list.
  * @index: Index of the node to be deleted.
  *
  * Return: 1 if node deleted successful, -1 if it fails.
  */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp_node = *head;

	if (*head == NULL)
		return (-1);

	while (index != 0)
	{
		if (tmp_node == NULL)
			return (-1);
		tmp_node = tmp_node->next;
		index--;
	}

	if (tmp_node == *head)
	{
		*head = tmp_node->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}
	else
	{
		tmp_node->prev->next = tmp_node->next;
		if (tmp_node->next != NULL)
			tmp_node->next->prev = tmp_node->prev;
	}
	free(tmp_node);
	return (1);
}
