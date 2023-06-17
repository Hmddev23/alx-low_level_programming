#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: This program prints all lowercase and uppercase
 *		letters of the alphabet using the putchar function.
 *
 * Return: 0 on successful execution
 */
int main(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; ++letter)
	{
		putchar(letter);
	}

	for (letter = 'A'; letter <= 'Z'; ++letter)
	{
		putchar(letter);
	}
	putchar('\n');

	return (0);
}
