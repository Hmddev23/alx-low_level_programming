#include <stdio.h>

/**
 * main - Print the the first 98 Fibonacci numbers
 *		starting with 1 and 2
 *
 * Return: Always 0.
 */
int main(void)
{
	long num1 = 0;
	long num2 = 1;
	int i;

	for (i = 0; i < 98; ++i)
	{
		long next = num1 + num2;

		printf("%ld, ", next);
		num1 = num2;
		num2 = next;
	}
	return (0);
}
