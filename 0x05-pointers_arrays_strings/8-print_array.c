#include <stdio.h>
#include "main.h"

/**
 * print_array - Print n elements of an array of integers.
 *
 * @a: Array to be printed.
 * @n: Number of elements to print.
 *
 * return: Nothing.
 */

void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (i == 0)
			printf("%d", a[i]);
		else
			printf(", %d", a[i]);
	}
	printf("\n");
}
