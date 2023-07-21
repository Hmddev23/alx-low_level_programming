#include "variadic_functions.h"

/**
  * print_numbers - Print numbers.
  *
  * @separator: String to print between numbers.
  * @n: Parameters counter.
  * @...: Integers to print.
  *
  * Return: Nothing.
  */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list arguments;
	unsigned int i;

	va_start(arguments, n);

	for (i = 0; i < n; i++)
	{
		if (!separator || (separator && i == 0))
		{
			printf("%d", va_arg(arguments, int));
		}
		else
		{
			printf("%s%d", separator, va_arg(arguments, int));
		}
	}

	va_end(arguments);

	printf("\n");
}
