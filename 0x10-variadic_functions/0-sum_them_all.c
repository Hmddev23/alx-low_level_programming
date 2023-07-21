#include "variadic_functions.h"

/**
  * sum_them_all - Calculate the sum of the arguments.
  *
  * @n: Number of arguments.
  *
  * Return: Sum of the arguments, or 0 if there are no arguments.
  */

int sum_them_all(const unsigned int n, ...)
{
	va_list arguments;
	unsigned int i;
	int sum = 0;

	if (n != 0)
	{
		va_start(arguments, n);
		while (i < n)
		{
			sum = sum + va_arg(arguments, int);
			i++;
		}

		va_end(arguments);
		return (sum);
	}

	return (0);
}
