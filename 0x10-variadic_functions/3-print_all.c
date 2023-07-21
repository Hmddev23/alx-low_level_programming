#include "variadic_functions.h"

/**
  * print_all - Print anything based on a specified format.
  *
  * @format: String parameter with the format specifiers for the arguments.
  * @...: Arguments to print.
  *
  * Return: Nothing.
  */

void print_all(const char * const format, ...)
{
	va_list args;
	const char *ptr = format;
	char c_arg;
	int i_arg;
	float f_arg;
	char *s_arg;

	va_start(args, format);
	while (format && *ptr)
	{
		switch (*ptr++)
		{
			case 'c':
				c_arg = va_arg(args, int);
				printf("%c", c_arg);
				break;
			case 'i':
				i_arg = va_arg(args, int);
				printf("%d", i_arg);
				break;
			case 'f':
				f_arg = va_arg(args, double);
				printf("%f", f_arg);
				break;
			case 's':
				s_arg = va_arg(args, char *);
				printf("%s", s_arg ? s_arg : "(nil)");
				break;
		}
		if (*ptr)
			printf(", ");
	}
	va_end(args);
	printf("\n");
}
