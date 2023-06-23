#include "main.h"

/**
 * print_most_numbers - check the code.
 *
 * Return: Nothing.
 */

void print_most_numbers(void)
{
	int nbr;

	for (nbr = '0'; nbr <= '9'; nbr++)
	{
		if (nbr != '2' && nbr != '4')
			_putchar (nbr);
	}
	_putchar ('\n');
}
