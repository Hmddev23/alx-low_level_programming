#include "main.h"

/**
  * multiply - Multiply two integers.
  *
  * @num1: Int parameter, the first integer.
  * @num2: Int parameter, the second integer.
  *
  * Return: Product of num1 and num2.
  */

int multiply(int num1, int num2)
{
	return (num1 * num2);
}

/**
  * isNumeric - Check if a string is numeric.
  *
  * @str: String parameter to check.
  *
  * Return: 1 if the string is numeric, 0 otherwise.
  */

int isNumeric(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}

	return (1);
}

/**
  * main - Entry point of the program.
  *
  * @argc: Argument counter.
  * @argv: Argument values.
  *
  * Return: always 0 (Success).
  */

int main(int argc, char *argv[])
{
	char *num1_str, *num2_str;
	int num1, num2, result;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	num1_str = argv[1];
	num2_str = argv[2];

	if (!isNumeric(num1_str) || !isNumeric(num2_str))
	{
		printf("Error\n");
		return (98);
	}

	num1 = atoi(num1_str);
	num2 = atoi(num2_str);

	result = multiply(num1, num2);

	printf("%d\n", result);

	return (0);
}
