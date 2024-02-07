#include "search_algos.h"

/**
  * recursive_binary_search - searche recursively for a value in a sorted
  * array of integers using binary search.
  *
  * @array: A pointer to the first element of the [sub]array to search.
  * @left: The starting index of the [sub]array to search.
  * @right: The ending index of the [sub]array to search.
  * @value: The value to search for.
  *
  * Return: Index where the value is located.
  */

int recursive_binary_search(int *array, size_t left, size_t right, int value)
{
	size_t i;

	if (right < left)
	{
		return (-1);
	}

	printf("Searching in array: ");
	for (i = left; i < right; i++)
	{
		printf("%d, ", array[i]);
	}
	printf("%d\n", array[i]);

	i = left + (right - left) / 2;
	if (array[i] == value && (i == left || array[i - 1] != value))
	{
		return (i);
	}

	if (array[i] >= value)
	{
		return (recursive_binary_search(array, left, i, value));
	}

	return (recursive_binary_search(array, i + 1, right, value));
}

/**
  * advanced_binary - searches for a value in a sorted array of integers.
  *
  * @array: Pointer to the first element of the array.
  * @size: Array length.
  * @value: Value to search for.
  *
  * Return: First index where the value is located.
  */

int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
	{
		return (-1);
	}

	return (recursive_binary_search(array, 0, size - 1, value));
}
