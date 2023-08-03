#include "main.h"

/**
  * binary_length - Find the length of @n.
  *
  * @n: Numeric value.
  *
  * Return: Length.
  */

int binary_length(unsigned long int n)
{
	int length = 0;

	while (n)
	{
		n >>= 1;
		length++;
	}

	return (length);
}

/**
  * print_binary - Prints the binary representation of an unsigned long int.
  *
  * @n: Unsigned long int to be printed.
  *
  * Return: Nothing.
  */

void print_binary(unsigned long int n)
{
	int length = binary_length(n);

	if (length == 0)
	{
		putchar('0');
	}
	else
	{
		unsigned long int mask = 1UL << (length - 1);

		while (mask)
		{
			if (n & mask)
			{
				putchar('1');
			}
			else
			{
				putchar('0');
			}
			mask >>= 1;
		}
	}
}
