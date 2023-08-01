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
	listint_t *current = *head;
	listint_t *next;

	if (head == NULL)
		return;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*head = NULL;
}

