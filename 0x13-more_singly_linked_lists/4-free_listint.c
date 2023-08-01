#include "lists.h"

/**
  * free_listint - free a linked list.
  *
  * @head: Pointer to the head of the list.
  *
  * Return: Nothing.
  */

void free_listint(listint_t *head)
{
	listint_t *current = head;
	listint_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
