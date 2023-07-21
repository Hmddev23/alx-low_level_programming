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
	va_list arguments;
	char *str;
	int num;
	char ch;
	float flt;

	va_start(arguments, format);
	while (*format)
	{
		if (*format == 'c')
		{
			ch = va_arg(arguments, int);
			printf("%c", ch);
		}
		else if (*format == 'i')
		{
			num = va_arg(arguments, int);
			printf("%d", num);
		}
		else if (*format == 'f')
		{
			flt = va_arg(arguments, double);
			printf("%f", flt);
		}
		else if (*format == 's')
		{
			str = va_arg(arguments, char *);
			if (str == NULL)
				printf("(nil)");
			else
				printf("%s", str);
		}
		format++;
	}
	va_end(arguments);
	printf("\n");
}
