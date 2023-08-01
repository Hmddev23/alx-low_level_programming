#include "lists.h"

/**
  * pop_listint - Delete head of the node.
  *
  * @head: Pointer to the first node in the list.
  *
  * Return: Head nodes data.
  */

int pop_listint(listint_t **head)
{
	listint_t *temp;
	int data;

	if (*head == NULL)
	{
		return (0);
	}

	data = (*head)->n;
	temp = *head;
	*head = (*head)->next;
	free(temp);

	return (data);
}
