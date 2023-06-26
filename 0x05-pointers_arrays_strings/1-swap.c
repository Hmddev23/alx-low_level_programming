#include "main.h"

/**
 * reset_to_98 - Function that swaps the values of two integers.
 *
 * @a : Parameter as pointer to first value.
 * @b : Parameter as pointer to second value.
 *
 * Return: Nothing.
 */

void swap_int(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
