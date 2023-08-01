#include "lists.h"

/**
  * add_nodeint_end - Add a new node at the end of the ll.
  *
  * @head: pointer to the first node of the list.
  * @n: element int to add to new node.
  *
  * Return: Address of the new head of the ll or NULL if it fails.
  */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node;

	new_node = (listint_t *)malloc(sizeof(listint_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		listint_t *current = *head;

		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}

	return (*head);
}
