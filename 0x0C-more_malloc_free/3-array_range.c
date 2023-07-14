#include "main.h"

/**
  * array_range - Create an array of integers.
  *
  * @min: Int parameter, min value.
  * @max: Int parameter, max value.
  *
  * Return: Array that contain all the values ordered from min to max.
  */

int *array_range(int min, int max)
{
	int numElements, i;
	int *arr;

	if (min > max)
		return (NULL);

	numElements = max - min + 1;
	arr = (int *)malloc(numElements * sizeof(int));

	if (arr == NULL)
		return (NULL);

	for (i = 0; i < numElements; i++)
		arr[i] = min++;

	return (arr);
}
