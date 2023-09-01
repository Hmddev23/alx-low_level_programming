#include "main.h"

/**
  * convert_binary_to_uint - Convert a binary number to an unsigned int.
  *
  * @binary_string: Pointer to a string of 0 and 1 chars.
  *
  * Return: Converted number, '0' or '1' if it fails.
  */

unsigned int convert_binary_to_uint(const char *binary_string)
{
	unsigned int result = 0;
	int bit;

	if (binary_string == NULL)
		return (0);

	while (*binary_string != '\0')
	{
	bit = *binary_string - '0';

		if (bit != 0 && bit != 1)
			return (0);

		result = (result << 1) | bit;
		binary_string++;
	}

	return (result);
}
