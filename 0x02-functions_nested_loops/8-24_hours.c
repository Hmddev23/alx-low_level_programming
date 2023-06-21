#include "main.h"

/**
 * File: 8-24_hours.c
 * Auth: Brennan D Baraban
 *
 * jack_bauer - check the code.
 *
 * jack_bauer - Prints every minute of the day of
 *		Jack Bauer, starting from 00:00 to 23:59.
 *
 * Return: Nothing.
 */
void jack_bauer(void)
{
	int h, m;

	for (h = 0; h <= 23; h++)
	{
		for (m = 0; m <= 59; m++)
		{
			_putchar((h / 10) + '0');
			_putchar((h % 10) + '0');
			_putchar(':');
			_putchar((m / 10) + '0');
			_putchar((m % 10) + '0');
			_putchar('\n');
		}
	}
}
