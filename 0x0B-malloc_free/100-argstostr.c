#include "main.h"

/**
  * argstostr - Concatenate all the arguments of the main function.
  *
  * @ac: Int parameter, argument counter.
  * @av: Double char pointer parameter, argument values.
  *
  * Return: Concatenated string from function arguments.
  */

char *argstostr(int ac, char **av)
{
	int i, j, k, length;
	char *string;

	if (ac == 0 || av == NULL)
		return (NULL);

	length = 0;
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			length++;
		length++;
	}

	string = (char *)malloc((length + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);

	k = 0;
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			string[k] = av[i][j];
			k++;
		}
		string[k] = '\n';
		k++;
	}
	string[k] = '\0';

	return (string);
}
