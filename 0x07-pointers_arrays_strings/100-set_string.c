#include "main.h"

/**
  * set_string - Set the value of a pointer to a char.
  *
  * @s: Pointer to pointer parameter.
  * @to: String to set.
  *
  * Return: Nothing.
  */

void set_string(char **s, char *to)
{
	*s = to;
}
