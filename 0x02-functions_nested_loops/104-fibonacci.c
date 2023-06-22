#include <stdio.h>

/**
 * main - Print the the first 98 Fibonacci numbers
 *		starting with 1 and 2
 *
 * Return: Always 0.
 */
int main(void)
{
	long num1 = 1;
	long num2 = 2;
	int i;

	for (i = 3; i <= 98; ++i) {
		int next = num1 + num2;
		printf("%ld\n", next);
    		num1 = num2;
		num2 = next;
	}
	return 0;
}
