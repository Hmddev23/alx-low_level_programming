#include "variadic_functions.h"

/**
  * print_strings - Print strings.
  *
  * @separator: String to print between numbers.
  * @n: Parameters counter.
  * @...: Strings to print.
  *
  * Return: Nothing.
  */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list arguments;
	unsigned int i;
	char *string;

	va_start(arguments, n);
	for (i = 0; i < n; i++)
	{
		string = va_arg(args, const char *);

		if (string == NULL)
			printf("(nil)");
		else
			printf("%s", string);

		if (i < n - 1 && separator != NULL)
			printf("%s", separator);
	}

	va_end(arguments);
	printf("\n");
}
