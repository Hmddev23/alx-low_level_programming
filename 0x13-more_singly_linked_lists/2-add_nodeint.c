#include "lists.h"

/**
  * add_nodeint - Add a new node at the beginning of a ll.
  *
  * @head: Pointer to the first node.
  * @n: Integer n to add in a new node.
  *
  * Return: Address of the new head of the ll or NULL if it fails.
  */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;
	*head = new_node;

	return (*head);
}
