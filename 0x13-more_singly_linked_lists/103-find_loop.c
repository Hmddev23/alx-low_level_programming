#include "lists.h"

/**
  * find_listint_loop - Find the loop in a linked list.
  *
  * @head: Head node of the linked list.
  *
  * Return: Address of the node, or NULL if there is no loop.
  */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head;
	listint_t *fast = head;

	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (slow);
		}
	}

	return (NULL);
}
