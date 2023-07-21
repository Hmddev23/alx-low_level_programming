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
	char ch;
	int int_val;
	float float_val;
	char *str_val;
	const char *format_ptr = format;

	va_start(args, format);

	while (*format_ptr != '\0')
	{
		if (*format_ptr == 'c')
		{
			ch = (char)va_arg(args, int);
			printf("%c", ch);
		}
		else if (*format_ptr == 'i')
		{
			int_val = va_arg(args, int);
			printf("%d", int_val);
		}
		else if (*format_ptr == 'f')
		{
			float_val = (float)va_arg(args, double);
			printf("%f", float_val);
		}
		else if (*format_ptr == 's')
		{
			str_val = va_arg(args, char *);
			if (str_val == NULL)
				printf("(nil)");
			else
				printf("%s", str_val);
		}

		format_ptr++;
	}

	va_end(args);

	printf("\n");
}
