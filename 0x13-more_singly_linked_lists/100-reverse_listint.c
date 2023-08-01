#include "lists.h"

/**
  * reverse_listint - Reverse a ll.
  *
  * @head: LL to reverse.
  *
  * Return: Pointer to the reversed list.
  */


listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *current = *head;

	while (current != NULL)
	{
		listint_t *next = current->next;

		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;
	return (*head);
}
