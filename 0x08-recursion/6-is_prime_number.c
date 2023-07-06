#include "main.h"

/**
  * is_prime_number - Returns if the input integer is a prime number.
  *
  * @n: Int parameter to evaluate.
  *
  * Return: 1 if the input is a prime number, otherwise return 0.
  */

int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}

	return (!is_divisible(n, n - 1));
}

/**
  * is_divisible - Check if n is divisible by a divisor.
  *
  * @n: Int parameter to check.
  * @divisor: Int parameter divisor.
  *
  * Return: 1 if n is prime, 0 if not
  */

int is_divisible(int n, int divisor)
{
	if (divisor == 1)
	{
		return (0);
	}

	if (n % divisor == 0)
	{
		return (1);
	}

	return (is_divisible(n, divisor - 1));
}
