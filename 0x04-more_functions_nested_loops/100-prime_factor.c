#include <stdio.h>

/**
 * main - Find and print the largest prime
 *        factor of the number 612852475143.
 *
 * Return: Always 0.
 */
int main(void)
{
	int fct;
	long prime = 612852475143;

	while (fct < (prime / 2))
	{
		if ((prime % 2) == 0)
		{
			prime /= 2;
			continue;
		}

		for (fct = 3; fct < (prime / 2); fct += 2)
		{
			if ((prime % fct) == 0)
				prime /= fct;
		}
	}
	printf("%ld\n", prime);

	return (0);
}
