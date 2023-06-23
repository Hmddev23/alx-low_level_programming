#include "main.h"

/**
 * print_number - Print an integer.
 *
 * @n: The integer to be printed.
 *
 * return: Nothing.
 */
void print_number(int n)
{
	unsigned int nbr = n;

	if (n < 0)
	{
		_putchar('-');
		nbr = -nbr;
	}

	if ((nbr / 10) > 0)
		print_number(nbr / 10);

	_putchar((nbr % 10) + '0');
}
