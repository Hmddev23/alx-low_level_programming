#include "hash_tables.h"

void hash_table_delete(hash_table_t *ht);

/**
  * hash_table_delete - Delete a hash table.
  *
  * @ht: Pointer to the hash table.
  *
  * Return: Nothing.
  */

void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *ht_head = ht;
	hash_node_t *ht_tmp, *node;
	unsigned long int idx;

	for (idx = 0; idx < ht->size; idx++)
	{
		if (ht->array[idx] != NULL)
		{
			node = ht->array[idx];
			while (node != NULL)
			{
				ht_tmp = node->next;
				free(node->key);
				free(node->value);
				free(node);
				node = ht_tmp;
			}
		}
	}
	free(ht_head->array);
	free(ht_head);
}
