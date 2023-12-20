#!/usr/bin/python3
"""
define an island perimeter measuring function.
"""

def island_perimeter(grid):
    """
    calculate the perimeter of the grid island.

    Args:
        grid (list of list of integers): The island zone.
        0 represents a water zone
        1 represents a land zone

    Returns:
        int: Perimeter of the island
    """

    if not grid or not grid[0]:
        return 0

    rows = len(grid)
    cols = len(grid[0])
    perimeter = 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                perimeter += 4

                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 1
                if i < rows - 1 and grid[i + 1][j] == 1:
                    perimeter -= 1
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 1
                if j < cols - 1 and grid[i][j + 1] == 1:
                    perimeter -= 1

    return perimeter
