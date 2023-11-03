#include "hash_tables.h"

/**
  * hash_djb2 - Hash function generates a djb2.
  *
  * @str: Pointer to hash of chars.
  *
  * Return: The hash key.
  */

unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int count;

	hash = 5381;
	while ((count = *str++))
	{
		hash = ((hash << 5) + hash) + count;
	}
	return (hash);
}
