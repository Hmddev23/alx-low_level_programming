#include "search_algos.h"

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
	size_t jump, jump_size;
	listint_t *node, *jump;

	if (list == NULL || size == 0)
	{
		return (NULL);
	}

	jump = 0;
	jump_size = sqrt(size);
	for (node = jump = list; jump->index + 1 < size && jump->n < value;)
	{
		node = jump;
		for (jump += jump_size; jump->index < jump; jump = jump->next)
		{
			if (jump->index + 1 == size)
			{
				break;
			}
		}
		printf("Value checked at index [%ld] = [%d]\n", jump->index, jump->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			node->index, jump->index);

	for (; node->index < jump->index && node->n < value; node = node->next)
	{
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	}
	printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);

	return (node->n == value ? node : NULL);
}
