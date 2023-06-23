/*
 * File: 10-print_triangle.c
 * Auth: ABDELHAMID-MAAIRA
 */

#include "main.h"

/**
 * print_triangle - Print a triangle.
 *
 * @size: The size of the triangle.
 *
 * return: Nothing.
 */
void print_triangle(int size)
{
	int head, index;

	if (size > 0)
	{
		for (head = 1; head <= size; head++)
		{
			for (index = size - head; index > 0; index--)
				putchar(' ');

			for (index = 0; index < head; index++)
				putchar('#');

			if (head == size)
				continue;

			putchar('\n');
		}
	}

	putchar('\n');
}
