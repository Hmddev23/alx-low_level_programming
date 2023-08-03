#include "main.h"

/**
  * set_bit - Set the value of a bit to 1 at a given index.
  *
  * @n: A pointer to the unsigned long int whose bit to set.
  * @index: The index of the bit to set.
  *
  * Return: 1 if it worked, or -1 if an error occurred.
  */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int num_bits = sizeof(unsigned long int) * 8;

	if (index >= num_bits)
	{
		return (-1);
	}

	unsigned long int mask = 1;

	mask <<= index;
	*n |= mask;

	return (1);
}
