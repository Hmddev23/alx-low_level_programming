#include "lists.h"

/**
  * free_listint2 - Free a ll of integers.
  *
  * @head: Double pointer to the head of the ll.
  *
  * Return: Nothing.
  */

void free_listint2(listint_t **head)
{
	listint_t *curr;

	if (head == NULL)
		return;

	while (*head)
	{
		curr = (*head)->next;
		free(*head);
		*head = curr;
	}
	*head = NULL;
}
