#include "hash_tables.h"

/**
  * key_index - Generate a hash table index for a key.
  *
  * @key: String parameter for the key
  * @size: Integer parameter ofr theSize of the hash table.
  *
  * Return: Hash table index for the specific key.
  */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
