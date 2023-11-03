#include "hash_tables.h"

/**
  * hash_table_print - Print a hash table.
  *
  * @ht: Pointer to the hash table.
  *
  * Return: Nothing.
  */

void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int cnt = 0, idx = 0;

	if (ht != NULL)
	{
		printf("{");
		for (idx = 0; idx < ht->size; idx++)
		{
			node = ht->array[idx];
			while (node != NULL)
			{
				if (cnt != 0)
					printf(", ");
				cnt = 1;
				printf("'%s': '%s'", node->key, node->value);
				node = node->next;
			}
		}
		printf("}\n");
	}
}
