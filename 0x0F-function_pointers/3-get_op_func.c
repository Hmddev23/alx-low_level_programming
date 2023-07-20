#include "3-calc.h"

/**
  * get_op_func - Select correct func to perform the operation.
  *
  * @s: Char pointer for operator.
  *
  * Return: Pointer to the function.
  */

int (*get_op_func(char *s))(int, int)
{
	int i;
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};

	i = 0;
	while (i < 5)
	{
		if (*s == *(ops[i]).op)
		{
			return (*(ops[i]).f);
		}
		i++;
	}

	return (NULL);
}
