#include "search_algos.h"

/**
  * custom_binary_search - custom binary search function.
  *
  * @array: Pointer to the array.
  * @left: first index of the [sub]array.
  * @right: last index of the [sub]array.
  * @value: Value to search for.
  *
  * Return: Index where the value is located.
  */

int custom_binary_search(int *array, size_t left, size_t right, int value)
{
	size_t index;

	if (array == NULL)
	{
		return (-1);
	}

	while (right >= left)
	{
		printf("Searching in array: ");
		for (index = left; index < right; index++)
		{
			printf("%d, ", array[index]);
		}
		printf("%d\n", array[index]);

		index = left + (right - left) / 2;
		if (array[index] == value)
		{
			return (index);
		}

		if (array[index] > value)
		{
			right = index - 1;
		}
		else
		{
			left = index + 1;
		}
	}

	return (-1);
}

/**
  * exponential_search - searche for a value in a sorted array
  * of integers using the Exponential search algorithm.
  *
  * @array: Pointer to the first element of the array.
  * @size: Array length.
  * @value: Value to search for.
  *
  * Return: Index where the value is located.
  */

int exponential_search(int *array, size_t size, int value)
{
	size_t index = 0, right;

	if (array == NULL)
	{
		return (-1);
	}

	if (array[0] != value)
	{
		for (index = 1; index < size && array[index] <= value; index = index * 2)
		{
			printf("Value checked array[%ld] = [%d]\n", index, array[index]);
		}
	}

	right = index < size ? index : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", index / 2, right);

	return (custom_binary_search(array, index / 2, right, value));
}
