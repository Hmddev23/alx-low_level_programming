#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: This program prints all the alphabet in
 *		lowercase except q and e.
 *
 * Return: 0 on successful execution
 */
int main(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; ++letter)
	{
		if (letter != 'e' && letter != 'q')
		{
			putchar(letter);
		}
	}
	putchar('\n');

	return (0);
}
