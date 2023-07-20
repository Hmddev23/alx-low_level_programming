#include <stdio.h>
#include <stdlib.h>

/**
  * main - Entry point of the program.
  *
  * @argc: number of arguments.
  * @argv: array of arguments.
  *
  * Return: Always 0 (Success).
  */

int main(int argc, char *argv[])
{
	int num_bytes, i;
	char *main_ptr;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	num_bytes = atoi(argv[1]);

	if (num_bytes < 0)
	{
		printf("Error\n");
		return (2);
	}

	main_ptr = (char *)main;

	for (i = 0; i < num_bytes; i++)
	{
		printf("%02x", main_ptr[i]);
		if (i < num_bytes - 1)
			printf(" ");
	}
	printf("\n");

	return (0);
}
