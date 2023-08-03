#include "main.h"

/**
  * get_bit - Return the value of a bit at a given index.
  *
  * @n: The unsigned long int to retrieve the bit from.
  * @index: The index of the bit to retrieve.
  *
  * Return: The value of the bit at index, or -1 if an error occurs.
  */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int num_bits = sizeof(unsigned long int) * 8;

	if (index >= num_bits)
	{
		return (-1);
	}

	unsigned long int mask = 1;

	mask <<= index;

	return ((n & mask) ? 1 : 0);
}
