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
	int mul;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	
	mul = (atoi(argv[1]) * atoi(argv[2]));
	printf("%d\n", mul);

	return (0);
}
