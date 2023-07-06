#include "main.h"

/**
  * _pow_recursion - Return value of x raised to the power of y.
  *
  * @x: Int parameter, base.
  * @y: Int parameter, power.
  *
  * Return: Value of x.
  */

int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return (-1);
	}

	if (y == 0)
	{
		return (1);
	}

	return (x * _pow_recursion(x, y - 1));
}
