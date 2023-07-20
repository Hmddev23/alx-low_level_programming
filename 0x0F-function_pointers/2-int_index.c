#include "function_pointers.h"

/**
  * int_index - Searche for an integer.
  *
  * @array: Int pointer array.
  * @size: Size of the array.
  * @cmp: Pointer to the comparison function.
  *
  * Return: int.
  */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array && cmp)
	{
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]))
				return (i);
		}
	}

	return (-1);
}
