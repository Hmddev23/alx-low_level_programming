#include "main.h"

/**
  * is_palindrome_helper - Recursive helper function.
  *
  * @start: Pointer parameter.
  * @end: Pointer parameter.
  *
  * Return: 1 if palindrome, 0 if not.
  */

int is_palindrome_helper(char *start, char *end)
{
	if (start >= end)
	{
		return (1);
	}

	if (*start != *end)
	{
		return (0);
	}

	return (is_palindrome_helper(start + 1, end - 1));
}

/**
  * _str_length - Return length of the string.
  *
  * @s: String parameter.
  *
  * Return: Length of the string.
  */

int _str_length(char *s)
{
	int length;

	length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}

	return (length);
}

/**
  * is_palindrome - Check if a string is a palindrome.
  *
  * @s: String parameter to check.
  *
  * Return: 1 if it is, 0 if it's not.
  */

int is_palindrome(char *s)
{
	int length;

	length = _str_length(s);

	if (length <= 1)
	{
		return (1);
	}

	return (is_palindrome_helper(s, s + length - 1));
}
