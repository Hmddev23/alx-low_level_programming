#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: This program print all the numbers
 *		of base 16 in lowercase.
 *
 * Return: 0 on successful execution
 */
int main(void)
{
	int number;

	for (number = 0; number <= 15; ++number)
	{
		if(number < 10)
		{
			putchar('0' + number);
		}
		else
		{
			putchar('a'+ number - 10);
		}
	}
	putchar('\n');

	return (0);
}
