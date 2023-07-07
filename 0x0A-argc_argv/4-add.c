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
	int i, number, sum;

	sum = 0;

	for (i = 1; i < argc; i++)
	{
		number = 0;

		while (argv[i][number] != '\0')
		{
			if (argv[i][number] < '0' || argv[i][number] > '9')
			{
				printf("Error\n");
				return (1);
			}
			number++;
		}

		sum += atoi(argv[i]);
	}

	printf("%d\n", sum);

	return (0);
}
