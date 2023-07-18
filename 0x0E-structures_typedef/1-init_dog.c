#include "dog.h"

/**
  * init_dog - function that initialize a variable of type struct dog.
  *
  * @d: Struct dog parameter.
  * @name: Name of dog.
  * @age: Age of dog.
  * @owner: Ownder of dog.
  *
  * Return: Nothing.
  */


void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
