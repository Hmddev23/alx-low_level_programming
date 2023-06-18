#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: This program print all possible combinations
 *		of two two-digit numbers.
 *
 * Return: 0 on successful execution
 */
int main(void)
{
	int nbr1, nbr2;

	for (nbr1 = 0; nbr1 <= 9; ++nbr1)
	{
		for (nbr2 = nbr1 + 1; nbr2 <= 9; ++nbr2)
		{
			putchar('0' + nbr1);
			putchar('0' + nbr2);
			if (nbr1 != 7 || nbr2 != 8)
				{
					putchar(',');
					putchar(' ');
				}
		}
	}
	putchar('\n');

	return (0);
}
