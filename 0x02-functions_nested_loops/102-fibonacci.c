#include <stdio.h>

/**
 * main - Print the first 50 Fibonacci numbers
 *		starting with 1 and 2.
 *
 * Return: Always 0.
 */
int main(void)
{
	int count;
	long fib1 = 0, fib2 = 1;
	long sum;

	for (count = 0; count < 50; count++)
	{
		sum = fib1 + fib2;
		printf("%ld", sum);

		fib1 = fib2;
		fib2 = sum;

		if (count == 49)
			printf("\n");
		else
			printf(", ");
	}

	return (0);
}
