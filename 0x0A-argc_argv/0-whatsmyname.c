#include "main.h"

/**
  * main - Entry point of the program.
  *
  * @argc: The number of command-line arguments.
  * @argv: An array of strings containing the command-line arguments.
  *
  * Return: Always 0 (success).
  */

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		if (argc == 1)
			printf("%s\n", argv[i]);
		else
			break;
	}

	return (0);
}
