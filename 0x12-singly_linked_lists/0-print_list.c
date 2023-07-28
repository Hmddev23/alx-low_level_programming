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
        size_t count = 0;

        printf("[");
        while (h != NULL)
        {
                if (h->str == NULL)
                {
                        printf("[0] (nil)");
                }
                else
                {
                        printf("[%u] %s", h->len, h->str);
                }

                h = h->next;
                count++;

                if (h != NULL)
                {
                        printf(", ");
                }
        }
        printf("]\n");

        return (count);
}
