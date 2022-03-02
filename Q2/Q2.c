#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 4

int path_exists(int mat[][N], int rows, int cols);


void main()
{
	int _mat[N][N] = { {1,0,0,0 }, {0,1,1,0}, {0,1,0,0}, {0,1,1,1}};
	printf("result is: %d", path_exists(_mat, N, N));
}

int path_exists(int mat[][N], int rows, int cols)
{

	// reached first position
	if (rows == 1 && cols == 1)
	{
		// check if there is a 1 in the first position
		if (mat[rows - 1][cols - 1] == 1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	// check if out of bounds of array
	if (rows == 0 || cols == 0)
	{
		return 0;
	}

	// check if last position ( the first position checked) has a zero in it
	if (mat[rows - 1][cols - 1] == 0)
	{
		return 0;
	}

	// go up
	// if not zero continue checking
	if (rows - 2 >= 0 && mat[rows - 2][cols - 1] == 1)
	{
		return path_exists(mat, rows - 1, cols);
	}

	// go left
	// if not zero continue checking
	if (cols - 2 >= 0 && mat[rows - 1][cols - 2] == 1)
	{
		return path_exists(mat, rows, cols - 1);
	}

	// go diagonaly
	// if not zero continue checking
	if (rows - 2 >= 0 && cols - 2 >= 0 && mat[rows - 2][cols - 2] == 1)
	{
		return path_exists(mat, rows - 1, cols - 1);
	}

	// if didn't continue in any path return zero
	return 0; 
}
