#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: This program print all possible different
 *		combinations of three digits.
 *
 * Return: 0 on successful execution
 */
int main(void)
{
	int nbr1, nbr2, nbr3;

	for (nbr1 = 0; nbr1 <= 9; ++nbr1)
	{
		for (nbr2 = nbr1 + 1; nbr2 <= 9; ++nbr2)
		{
			for (nbr3 = nbr2 + 1; nbr3 <= 9; ++nbr3)
			{
				putchar('0' + nbr1);
				putchar('0' + nbr2);
				putchar('0' + nbr3);
				if (nbr1 != 7 || nbr2 != 8 || nb3 != 9)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');

	return (0);
}
