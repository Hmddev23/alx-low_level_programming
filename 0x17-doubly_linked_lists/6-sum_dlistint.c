#include "lists.h"

/**
  * sum_dlistint - Calculate the sum of all the values in a dll.
  *
  * @head: Pointer to the head of the dll.
  *
  * Return: Sum of all the node values.
  */

int sum_dlistint(dlistint_t *head)
{
	int total = 0;

	if (head == NULL)
		return (0);

	while (head)
	{
		total += head->n;
		head = head->next;
	}

	return (total);
}
