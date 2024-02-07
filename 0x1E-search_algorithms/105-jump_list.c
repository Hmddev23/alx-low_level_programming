#include "search_algos.h"

/**
  * move_forward - move a list forward until the index
  * matches a desired index.
  *
  * @list: List to check.
  * @index: Desired index.
  *
  * Return: Desired index.
  */

listint_t *move_forward(listint_t *list, size_t index)
{
	while (list->next != NULL && list->index < index)
	{
		list = list->next;
	}

	return (list);
}

/**
  * jump_list - searche for a value in a sorted list
  * of integers using the Jump search algorithm.
  *
  * @list: Pointer to the head of the linked list.
  * @size: The list length.
  * @value: Value to search for.
  *
  * Return: Pointer to the first node where the value is located.
  */

listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t jump;
	listint_t *left, *right;

	if (list != NULL && size > 0)
	{
		jump = sqrt(size);
		left = list;
		right = move_forward(left, jump);
		printf("Value checked at index [%lu] = [%d]\n", right->index, right->n);
		while (right->index < (size - 1) && right->n < value)
		{
			left = right;
			right = move_forward(left, right->index + jump);
			printf("Value checked at index [%lu] = [%d]\n", right->index, right->n);
		}
		printf("Value found between indexes [%lu] and [%lu]\n",
				left->index, right->index);
		printf("Value checked at index [%lu] = [%d]\n", left->index, left->n);
		while (left->index < size - 1 && left->n < value)
		{
			left = left->next;
			if (left == NULL)
				return (NULL);
			printf("Value checked at index [%lu] = [%d]\n", left->index, left->n);
		}
		if (left->n == value)
			return (left);
	}
	return (NULL);
}
