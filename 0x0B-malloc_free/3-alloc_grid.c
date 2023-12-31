#include "main.h"

/**
  * alloc_grid - Create 2 dimensional array of integers.
  *
  * @width: Int parameter for rows.
  * @height: Int parameter for cols.
  *
  * Return: Pointer to a 2 dimensional array of integers.
  */

int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j, k;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = (int **)malloc(height * sizeof(int *));
	if (grid == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		grid[i] = (int *)malloc(width * sizeof(int));
		if (grid[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(grid[j]);

			free(grid);
			return (NULL);
		}

		for (k = 0; k < width; k++)
			grid[i][k] = 0;
	}

	return (grid);
}
