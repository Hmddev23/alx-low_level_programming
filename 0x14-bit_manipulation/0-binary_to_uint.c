#include "main.h"

/**
  * binary_to_uint - Convert a binary number to an unsigned int.
  *
  * @b: Pointer to a string of 0 and 1 chars.
  *
  * Return: Converted number, '0' or '1' if it fails.
  */

unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int bit;

	if (b == NULL)
		return (0);

	while (*b != '\0')
	{
		bit = *b - '0';

		if (bit != 0 && bit != 1)
			return (0);

		result = (result << 1) | bit;
		b++;
	}

	return (result);
}
