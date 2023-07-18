#include "dog.h"

/**
  * string_length - Calculate the length of a string.
  *
  * @str: The input string.
  *
  * Return: Length of the string.
  */

int string_length(const char *str)
{
	int length = 0;

	while (str[length] != '\0')
	{
		length++;
	}

	return (length);
}

/**
  * string_copy - Copy a string from source to destination.
  *
  * @dest: The destination string.
  * @src: The source string.
  *
  * Return: Nothing.
  */

void string_copy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
}

/**
  * new_dog - Create a new dog structure.
  *
  * @name: The name of the dog.
  * @age: The age of the dog.
  * @owner: The owner of the dog.
  *
  * Return: Pointer to the created dog structure, or NULL.
  */

dog_t *new_dog(char *name, float age, char *owner)
{
	int name_length = string_length(name);
	int owner_length = string_length(owner);
	dog_t *new_dog;

	if (name == NULL || owner == NULL)
	{
		return (NULL);
	}

	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
	{
		return (NULL);
	}

	new_dog->name = malloc((name_length + 1) * sizeof(char));
	new_dog->owner = malloc((owner_length + 1) * sizeof(char));

	if (new_dog->name == NULL || new_dog->owner == NULL)
	{
		free(new_dog->name);
		free(new_dog->owner);
		free(new_dog);
		return (NULL);
	}

	string_copy(new_dog->name, name);
	string_copy(new_dog->owner, owner);

	new_dog->age = age;

	return (new_dog);
}
