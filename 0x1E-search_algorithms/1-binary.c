#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
  * binary_search - searche for a value in a sorted array
  * with the Binary search algorithm.
  *
  * @array: Array of values.
  * @size: Size of the array.
  * @value: Value to search for.
  *
  * Return: Searched value.
  */

int binary_search(int *array, size_t size, int value)
{
	size_t first = 0;
	size_t second = size - 1;
	size_t center;
	size_t i;

	if (!array)
	{
		return (-1);
	}

	while (first <= second)
	{
		center = first + (second - first) / 2;

		printf("Searching in array: ");
		for (i = first; i <= second; i++)
		{
			printf("%d", array[i]);
			if (i < second)
			{
				printf(", ");
			}
			else
			{
				printf("\n");
			}
		}

		if (array[center] == value)
		{
			return (center);
		}

		if (array[center] < value)
			first = center + 1;
		else
			second = center - 1;
	}

	return (-1);
}
