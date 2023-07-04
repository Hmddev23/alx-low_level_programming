#include "main.h"

/**
  * print_chessboard - print the chessboard.
  *
  * @a: 2 dimension array to print.
  *
  * Return: Nothing.
  */

void print_chessboard(char (*a)[8])
{
	int line, column;

	for (line = 0; line < 8; line++)
	{
		for (column = 0; column < 8; column++)
		{
			_putchar(a[line][column]);
		}
		_putchar ('\n');
	}
}
