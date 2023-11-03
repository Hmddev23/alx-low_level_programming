#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
  * shash_table_create - Create a sorted hash table.
  *
  * @size: Size of the sorted hash table.
  *
  * Return: Pointer to the sorted hash table, otherwise NULL.
  */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *hsh_tab;
	unsigned long int idx;

	hsh_tab = malloc(sizeof(shash_table_t));
	if (hsh_tab == NULL)
		return (NULL);

	hsh_tab->size = size;
	hsh_tab->array = malloc(sizeof(shash_node_t *) * size);
	if (hsh_tab->array == NULL)
		return (NULL);
	for (idx = 0; idx < size; idx++)
		hsh_tab->array[idx] = NULL;
	hsh_tab->shead = NULL;
	hsh_tab->stail = NULL;

	return (hsh_tab);
}

/**
  * shash_table_set - Add an element to a sorted hash table.
  *
  * @ht: Pointer to the sorted hash table.
  * @key: Key to add.
  * @value: Value associated with the key.
  *
  * Return: 0 on fail.
  */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *h_new, *h_tmp;
	char *value_copy;
	unsigned long int idx;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	h_tmp = ht->shead;
	while (h_tmp)
	{
		if (strcmp(h_tmp->key, key) == 0)
		{
			free(h_tmp->value);
			h_tmp->value = value_copy;
			return (1);
		}
		h_tmp = h_tmp->snext;
	}

	h_new = malloc(sizeof(shash_node_t));
	if (h_new == NULL)
	{
		free(value_copy);
		return (0);
	}
	h_new->key = strdup(key);
	if (h_new->key == NULL)
	{
		free(value_copy);
		free(h_new);
		return (0);
	}
	h_new->value = value_copy;
	h_new->next = ht->array[idx];
	ht->array[idx] = h_new;

	if (ht->shead == NULL)
	{
		h_new->sprev = NULL;
		h_new->snext = NULL;
		ht->shead = h_new;
		ht->stail = h_new;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		h_new->sprev = NULL;
		h_new->snext = ht->shead;
		ht->shead->sprev = h_new;
		ht->shead = h_new;
	}
	else
	{
		h_tmp = ht->shead;
		while (h_tmp->snext != NULL && strcmp(h_tmp->snext->key, key) < 0)
			h_tmp = h_tmp->snext;
		h_new->sprev = h_tmp;
		h_new->snext = h_tmp->snext;
		if (h_tmp->snext == NULL)
			ht->stail = h_new;
		else
			h_tmp->snext->sprev = h_new;
		h_tmp->snext = h_new;
	}

	return (1);
}

/**
  * shash_table_get - Retrieve the value of the key.
  *
  * @ht: Pointer to the sorted hash table.
  * @key: Key to get the value of.
  *
  * Return: Value associated with key in hash table.
  */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *h_node;
	unsigned long int idx;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	idx = key_index((const unsigned char *)key, ht->size);
	if (idx >= ht->size)
		return (NULL);

	h_node = ht->shead;
	while (h_node != NULL && strcmp(h_node->key, key) != 0)
		h_node = h_node->snext;

	return ((h_node == NULL) ? NULL : h_node->value);
}

/**
  * shash_table_print - Print the sorted hash table in order.
  *
  * @ht: Pointer to the sorted hash table.
  *
  * Return: Nothing.
  */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *h_node;

	if (ht == NULL)
		return;

	h_node = ht->shead;
	printf("{");
	while (h_node != NULL)
	{
		printf("'%s': '%s'", h_node->key, h_node->value);
		h_node = h_node->snext;
		if (h_node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
  * shash_table_print_rev - Print the sorted hash table in reverse.
  *
  * @ht: A pointer to the sorted hash table.
  *
  * Return: Nothing.
  */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *h_node;

	if (ht == NULL)
		return;

	h_node = ht->stail;
	printf("{");
	while (h_node != NULL)
	{
		printf("'%s': '%s'", h_node->key, h_node->value);
		h_node = h_node->sprev;
		if (h_node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
  * shash_table_delete - Delete the sorted hash table.
  *
  * @ht: Pointer to the sorted hash table.
  *
  * Return: Nothing.
  */

void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *h_node, *h_tmp;

	if (ht == NULL)
		return;

	h_node = ht->shead;
	while (h_node)
	{
		h_tmp = h_node->snext;
		free(h_node->key);
		free(h_node->value);
		free(h_node);
		h_node = h_tmp;
	}

	free(head->array);
	free(head);
}
