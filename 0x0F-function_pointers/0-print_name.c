#include "function_pointers.h"

/**
  * print_name - Print a name.
  *
  * @name: Name of the person.
  * @f: Input pointer to f function.
  *
  * Return: Nothing.
  */

void print_name(char *name, void (*f)(char *))
{
	if (name != 0 && f != 0)
	{
		f(name);
	}
}
