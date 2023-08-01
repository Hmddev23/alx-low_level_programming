#include "lists.h"

/**
  * get_nodeint_at_index - Get node at index from a ll.
  *
  * @head: Pointer to the first node of the list.
  * @index: Index of node to access.
  *
  * Return: Index of nth node OR NULL if node doesn't exist.
  */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current = head;
	unsigned int count = 0;

	while (current != NULL)
	{
		if (count == index)
		{
			return (current);
		}

		current = current->next;
		count++;
	}

	return (NULL);
}
