#include "hash_tables.h"

/**
  * hash_table_get - Retrieve a value associated with a key in a hash table.
  *
  * @ht: Pointer to the hash table.
  * @key: Key to search for in the hash table.
  *
  * Return: Value associated with that key.
  */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node;
	unsigned long int index;

	if (key == NULL || ht == NULL)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	for (; node != NULL; node = node->next)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
	}
	return (NULL);
}
