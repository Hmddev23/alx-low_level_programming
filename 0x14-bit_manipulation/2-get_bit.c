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
	unsigned long int bit_num;

	if (sizeof(n) * 8 < index)
	{
		return (-1);
	}

	bit_num = n >> index;

	return (bit_num & 1);
}
