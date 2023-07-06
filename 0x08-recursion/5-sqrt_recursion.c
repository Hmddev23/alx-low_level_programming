#include "main.h"

/**
  * _sqrt_recursion - Return natural square root of a number.
  *
  * @n: Int paramater.
  *
  * Return: Sqrt of n.
  */

int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}

	return (_sqrt_helper(n, 0, n));
}

/**
  * _sqrt_helper - _sqrt_recursion.
  *
  * @n: Int parameter.
  * @start: Int parameter.
  * @end: Int parameter.
  *
  * Return: Sqrt.
  */

int _sqrt_helper(int n, int start, int end)
{
	if (start > end)
	{
		return (-1);
	}

	int mid, square;

	mid = (start + end) / 2;
	square = mid * mid;

	if (square == n)
	{
		return (mid);
	}
	else if (square > n)
	{
		return (_sqrt_helper(n, start, mid - 1));
	}
	else
	{
		return (_sqrt_helper(n, mid + 1, end));
	}
}
