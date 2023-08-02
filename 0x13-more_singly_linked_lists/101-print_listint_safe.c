#include "lists.h"

/**
  * print_listint_safe -  Print a listint_t linked list.
  *
  * @head: Head node of the list.
  *
  * Return: The number of nodes in the list.
  */

size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow = head;
	const listint_t *fast = head;
	size_t count = 0;

	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		slow = slow->next;
		fast = fast->next->next;
		count++;

		if (slow == fast)
		{
			printf("[%p] %d\n", (void *)slow, slow->n);
			break;
		}
	}

	if (slow == fast)
	{
		printf("-> [%p] %d\n", (void *)slow, slow->n);
		slow = slow->next;
		count++;

		while (slow != fast)
		{
			printf("[%p] %d\n", (void *)slow, slow->n);
			slow = slow->next;
			count++;
		}
	}
	else
	{
		while (slow != NULL)
		{
			printf("[%p] %d\n", (void *)slow, slow->n);
			slow = slow->next;
			count++;
		}
	}

	return (count);
}
