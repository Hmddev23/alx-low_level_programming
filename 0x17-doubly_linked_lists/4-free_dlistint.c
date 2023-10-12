#include "lists.h"

/**
  * free_dlistint - Free a doubly linked list.
  *
  * @head: Pointer to the head of the list.
  *
  * Return: Nothing.
  */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp_node;

	while (head)
	{
		tmp_node = head->next;
		free(head);
		head = tmp_node;
	}
}
