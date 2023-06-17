#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point of the program
 *
 * Description: This program generates a random number, extracts its last digit using 
 * 		the modulo operator (%), and prints a message indicating its properties:
 * 		greater than 5, equal to 0, or less than 6 and not equal to 0.
 *
 * Return: 0 on successful execution
 */
int main(void)
{
    	int n;
	int ld;

    	srand(time(0));
   	n = rand() - RAND_MAX / 2;
	/* your code goes there */
    	ld = n % 10;

    	if (n > 5)
    	{
        	printf("Last digit of %d is %d and is greater than 5\n", n, ld);
    	}
    	else if (n == 0)
    	{
        	printf("Last digit of %d is %d and is 0\n", n, ld);
    	}
    	else if (n < 6 && n != 0)
    	{
        	printf("Last digit of %d is %d and is less than 6 and not 0\n", n, ld);
    	}
	else
	{
		printf("something went wrong!");
	}

    	return (0);
}
