#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: This program print all possible combinations
 *		of single-digit numbers.
 *
 * Return: 0 on successful execution
 */
int main(void)
{
	int number;

	for (number = 0; number <= 9; ++number)
	{
		putchar('0' + number);
		if (number != 9)
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');

	return (0);
}
