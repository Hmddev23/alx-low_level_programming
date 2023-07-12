#include "main.h"

/**
  * argstostr - a function that concatenates
  *
  * @ac: Int parameter, argument counter.
  * @av: Double char pointer parameter, argument values.
  *
  * Return: Concatenated string from function arguments.
  */

char *argstostr(int ac, char **av)
{
	char *result;
	int total_length, newline_count, index;
	int i, k;

	if (ac == 0 || av == NULL)
		return (NULL);
	total_length = 0;
	newline_count = ac - 1;
	for (i = 0; i < ac; i++)
	{
		char *arg = av[i];
		int arg_length = 0;
		while (*arg != '\0')
		{
			arg_length++;
			arg++;
		}
		total_length += arg_length;
	}
	total_length += newline_count;
	result = (char *)malloc((total_length + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	index = 0;
	for (k = 0; k < ac; k++)
	{
		char *arg = av[k];
		while (*arg != '\0')
		{
			result[index] = *arg;
			index++;
			arg++;
		}
		if (k != ac - 1)
		{
			result[index] = '\n';
			index++;
		}
	}
	result[total_length] = '\0';
	return (result);
}
