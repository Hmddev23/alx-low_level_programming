#include "main.h"

/**
 * swap_int - Function that swaps the values of two integers.
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
