#include "main.h"

/**
  * multiply - Multiply two integers.
  *
  * @num1: Char pointer parameter, first number as string.
  * @num2: Char pointer parameter, second number as string.
  * @result: Char Pointer parameter, to store the product.
  *
  * Return: Nothing.
  */

void multiply(const char *num1, const char *num2, char *result)
{
	int len1, len2, maxDigits, i, j, k, l, index, start;
	int *res;

	len1 = 0;
	len2 = 0;
	while (num1[len1] != '\0')
		len1++;
	while (num2[len2] != '\0')
		len2++;
	maxDigits = len1 + len2;
	res = (int *)malloc(sizeof(int) * (maxDigits));
	for (l = 0; l < maxDigits; l++)
		res[l] = 0;
	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			int digit1 = num1[i] - '0';
			int digit2 = num2[j] - '0';
			res[i + j + 1] += digit1 * digit2;
		}
	}
	for (k = maxDigits - 1; k > 0; k--)
	{
		res[k - 1] += res[k] / 10;
		res[k] %= 10;
	}
	index = 0;
	start = 0;
	while (res[start] == 0 && start < maxDigits - 1)
		start++;
	while (start < maxDigits)
		result[index++] = res[start++] + '0';
	result[index] = '\0';
	free(res);
}

/**
  * isNumeric - Check if a string is numeric.
  *
  * @str: String parameter to check.
  *
  * Return: 1 if the string is numeric, 0 otherwise.
  */

int isNumeric(const char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
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
	char *num1, *num2, *result;
	int maxDigits;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	num1 = argv[1];
	num2 = argv[2];

	if (!isNumeric(num1) || !isNumeric(num2))
	{
		printf("Error\n");
		return (98);
	}

	maxDigits = 0;
	while (num1[maxDigits] != '\0')
		maxDigits++;

	while (num2[maxDigits] != '\0')
		maxDigits++;

	result = (char *)malloc(sizeof(char) * (maxDigits + 1));
	multiply(num1, num2, result);

	printf("%s\n", result);

	free(result);

	return (0);
}

