#include <stdio.h>
#include "main.h"

/**
  * print_diagsums - print sum of two diagonal matrix.
  *
  * @a: a pointer.
  * @size: size.
  *
  * Return: Nothing.
  */

void print_diagsums(int *a, int size)
{
	int sum1, sum2, index;

	sum1 = 0;
	sum2 = 0;

	for (index = 0; index < size; index++)
	{
		sum1 += a[index * size + index];
		sum2 += a[index * size + (size - 1 - index)];
	}

	printf("%d, %d\n", sum1, sum2);
}
