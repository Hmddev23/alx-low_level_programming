#include "lists.h"

/**
  * sum_listint - Get the sum of all the nodes data.
  *
  * @head: Pointer to the first node.
  *
  * Return: Sum of all nodes.
  */

int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *current = head;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
