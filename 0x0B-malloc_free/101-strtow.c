#include "main.h"

/**
  * wordcount - Count how many words.
  *
  * @str: String parameter.
  *
  * Return: Number of words.
  */

int count_words(char *str)
{
	int words = 0;

	while (*str != '\0')
	{
		if (*str == ' ')
			str++;
		else
		{
			while (*str != ' ' && *str != '\0')
				str++;
			words++;
		}
	}

	return (words);
}

/**
  * free_memory - Free located memory.
  *
  * @ar: Double char pointer to the grid.
  * @i: Int parameter.
  *
  * Return: Nothing.
  */

void free_memory(char **ar, int size)
{
	int i;
	if (ar != NULL)
	{
		for (i = 0; i < size; i++)
			free(ar[i]);
		free(ar);
	}
}

/**
  * strtow - Split a string into words.
  *
  * @str: String parameter to split.
  *
  * Return: Pointer to an array of strings (words).
  */

char **strtow(char *str)
{
	int i, j, start, word_length;
	int str_length = count_words(str);
	char **string = NULL;

	if (str == NULL || *str == '\0' || str_length == 0)
		return (NULL);

	string = (char **)malloc((str_length + 1) * sizeof(char *));
	if (string == NULL)
		return (NULL);

	i = 0;
	start = 0;
	word_length = 0;
	while (i < str_length)
	{
		while (str[start] == ' ')
			start++;

		while (str[start + word_length] != ' ' && str[start + word_length] != '\0')
			word_length++;
		string[i] = (char *)malloc((word_length + 1) * sizeof(char));
		if (string[i] == NULL)
		{
			free_memory(string, i);
			return (NULL);
		}
		for (j = 0; j < word_length; j++)
			string[i][j] = str[start + j];
		string[i][word_length] = '\0';

		start += word_length;
		word_length = 0;
		i++;
	}
	string[str_length] = NULL;
	return (string);
}
