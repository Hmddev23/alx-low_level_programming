#include "main.h"

/**
  * free_grid - Free a 2 dimensional grid.
  *
  * @grid: Double int pointer parameter to the grid.
  * @height: Int parameter, height of the array.
  *
  * Return: Nothing.
  */

void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL)
		return;

	for (i = 0; i < height; i++)
		free(grid[i]);

	free(grid);
}
