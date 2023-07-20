#include "function_pointers.h"

/**
  * array_iterator - Get each element of an array.
  *
  * @array: Int pointer array.
  * @size: Size of the array.
  * @action: Pointer to a function.
  *
  * Return: Nothing.
  */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int index = 0;

	if (array != 0 && size >= 1 && action != 0)
	{
		while (index < size)
		{
			action(array[index]);
			index++;
		}
	}
}
