#include "main.h"

/**
 * _atoi - Converts a string to an integer.
 *
 * @s: String parameter to be converted.
 *
 * Return: Converted integer.
 */

int _atoi(char *s)
{
	int index, result, valid, sign, length, digit;

	index = 0;
	sign = 0;
	result = 0;
	length = 0;
	valid = 0;
	digit = 0;

	while (s[length])
		length++;

	while (index < length && valid == 0)
	{
		if (s[index] == '-')
			++sign;

		if (s[index] >= '0' && s[index] <= '9')
		{
			digit = s[index] - '0';
			if (sign % 2)
				digit = -digit;

			result = result * 10 + digit;
			valid = 1;

			if (s[index + 1] < '0' || s[index + 1] > '9')
				break;
			valid = 0;
		}
		index++;
	}

	if (valid == 0)
		return (0);

	return (result);
}
