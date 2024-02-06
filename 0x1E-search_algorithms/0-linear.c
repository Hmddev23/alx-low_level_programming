#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
  * linear_search - searche for a value in an array
  * with Linear search algorithm.
  *
  * @array: Array.
  * @size: Array size.
  * @value: Value to search for.
  *
  * Return: The Value to search for.
  */

int linear_search(int *array, size_t size, int value)
{
	size_t i = 0;

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
		{
			return (i);
		}
	}

	return (-1);
}
