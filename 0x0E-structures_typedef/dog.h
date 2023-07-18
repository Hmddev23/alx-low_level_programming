#ifndef DOG_H
#define DOG_H

/**
  * struct dog - Structure representing a dog.
  *
  * @name: Name of the dog
  * @age: Age of the dog
  * @owner: Owner of the dog
  *
  * This structure represents a dog and is used to store
  * information about individual dogs within a program.
  * It consists of three members: 'name' which is a character
  * pointer holding the name of the dog, 'age' which is a float
  * indicating the age of the dog, and 'owner' which is a character
  * pointerrepresenting the owner of the dog.
  */

struct dog
{
	char *name;
	float age;
	char *owner;
};

#endif /* DOG_H */
