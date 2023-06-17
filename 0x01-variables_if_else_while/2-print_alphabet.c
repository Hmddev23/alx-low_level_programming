#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point of the program
 *
 * Description: This program prints all lowercase letters of
 *		the alphabet using the putchar function.
 *
 * Return: 0 on successful execution
 */
int main(void)
{
	char letter;

	for(letter = 'a'; letter <= 'z'; ++letter)
	{
		putchar(letter);
	}

        return (0);
}
