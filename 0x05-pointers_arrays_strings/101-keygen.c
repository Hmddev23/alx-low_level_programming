#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Program that generates random valid
 *	passwords for the program 101-crackme.
 *
 * Return: Always 0 (Success).
 */

int main(void)
{
	int i, password_length;
	char password[password_length + 1];

	srand(time(NULL));
	password_length = 10;

	for (i = 0; i < password_length; i++) {
		password[i] = 'A' + rand() % 26;
	}
	password[password_length] = '\0';
	printf("%s\n", password);
	
	return (0);
}
