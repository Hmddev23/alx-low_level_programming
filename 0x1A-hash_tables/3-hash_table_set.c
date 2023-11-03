#include "hash_tables.h"

/**
  * hash_table_set - Add the value of a key to the hash table.
  *
  * @ht: Hash table to be updated.
  * @key: Key to be added.
  * @value: New value to be associated with the key.
  *
  * Return: Returns 1 if successful, 0 if an error occurred.
  */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long idx, size;
	hash_node_t *n_node;

	if (ht  == NULL || key == NULL || value == NULL)
		return (0);

	size = ht->size;
	idx = key_index((const unsigned char *)key, size);

	if (ht->array[idx] != NULL && strcmp(ht->array[idx]->key, key) == 0)
	{
		ht->array[idx]->value = strdup(value);
		return (1);
	}

	n_node = malloc(sizeof(hash_node_t));

	if (n_node == NULL)
		return (0);

	n_node->key = strdup(key);
	n_node->value = strdup(value);
	n_node->next = ht->array[idx];
	ht->array[idx] = n_node;
	return (1);
}
