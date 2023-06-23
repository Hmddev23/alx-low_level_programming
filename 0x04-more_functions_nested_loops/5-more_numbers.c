#include "main.h"

/**
 * more_numbers - check the code.
 *
 * Return: Nothing.
 */

void more_numbers(void)
{
	int i, nbr;

	for (i = 0; i < 10; i++)
	{
		for (nbr = 0; nbr <= 14; nbr++)
		{
			if (nbr > 9)
			{
				_putchar ('0' + nbr / 10);
			}
			_putchar ('0' + nbr % 10);
		}
		_putchar('\n');
	}

	return 0;
}
