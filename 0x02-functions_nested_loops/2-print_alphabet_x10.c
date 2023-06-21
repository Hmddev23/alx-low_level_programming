#include "main.h"

/**
 * print_alphabet_x10 - check the code.
 *
 * Description: This program prints the alphabet
 *		in lowercase 10 times.
 *
 * Return: Nothing.
 */
void print_alphabet_x10(void)
{
	char letter;
	int i;

	for (i = 0; i < 10; i++)
	{
		for (letter = 'a'; letter <= 'z'; ++letter)
		{
			_putchar(letter);
		}
		_putchar('\n');
	}
}
