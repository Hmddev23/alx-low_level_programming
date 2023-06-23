#include "main.h"

/**
  * print_square -  print a square.
  * @counter :parameter
  * Return: Nothing.
  */

void print_square(int counter)
{
	int row, column;

	if (counter <= 0)
		_putchar('\n');

	for (row = 0; row < counter; row++)
	{
		for (column = 0; column < counter; column++)
		{
			_putchar('#');
		}
		_putchar('\n');
	}
}
