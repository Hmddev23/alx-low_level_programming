#include "lists.h"

/**
  * print_list - Print elements in a linked list.
  *
  * @h: Pointer first node.
  *
  * Return: Number of nodes.
  */

size_t print_list(const list_t *h)
{
	size_t node_ctr;

	if (h == NULL)
	{
		return (0);
	}

	node_ctr = 0;
	while (h != NULL)
	{
		if (h->str == NULL)
		{
			printf("[%d] %s\n", 0, "(nil)");
		}
		else
		{
			printf("[%d] %s\n", h->len, h->str);
		}
		h = h->next;
		node_ctr++;
	}

	printf("[%d] %s\n", h->len, h->str);

	return (node_ctr);
}
