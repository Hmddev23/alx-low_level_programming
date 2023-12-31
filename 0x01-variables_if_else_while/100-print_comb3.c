#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: This program print all possible different
 *		combinations of two digits.
 *
 * Return: 0 on successful execution
 */
int main(void)
{
	int nbr1;
	int nbr2;

	for (nbr1 = 0; nbr1 <= 9; ++nbr1)
	{
		for (nbr2 = nbr1 + 1; nbr2 <= 9; ++nbr2)
		{
			putchar('0' + nbr1);
			putchar('0' + nbr2);
			if (nbr1 != 8 || nbr2 != 9)
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');

	return (0);
}
