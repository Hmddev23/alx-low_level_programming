#include "lists.h"

/**
  * free_list - Frees a list_t list.
  *
  * @head: Pointer to the head node of the list.
  *
  * Return: Nothing.
  */

void free_list(list_t *head)
{
	list_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current->str);
		free(current);
	}
}
