#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 4

int path_exists(int mat[][N], int rows, int cols);


void main()
{
	// user input the array
	int _mat[N][N];

	// get all matrix numbers from user
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("Please insert number for row %d column %d:", i+1, j+1);
			scanf("%d", &_mat[i][j]);
		}
	}
	
	// return descriptive result to user
	if (path_exists(_mat, N, N)) {
		printf("A path from start to finish exists\n");
	}
	else {
		printf("A path from start to finish does not exist!\n");
	}
	
}

/// <summary>
/// A function that scans a matrix to see if a path exists from point (0,0) to point (n-1,n-1)
/// </summary>
/// <param name="mat">the matrix scanned</param>
/// <param name="rows">number of rows</param>
/// <param name="cols">number of columns</param>
/// <returns>1 if there is a column and 0 if there isn't</returns>
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

	// continue checking on all three paths (up, left, diagonal left up)
	if ((rows - 2 >= 0 && mat[rows - 2][cols - 1] == 1) ||
		(cols - 2 >= 0 && mat[rows - 1][cols - 2] == 1) ||
		(rows - 2 >= 0 && cols - 2 >= 0 && mat[rows - 2][cols - 2] == 1))
	{
		int result = path_exists(mat, rows - 1, cols) + path_exists(mat, rows, cols - 1) + path_exists(mat, rows - 1, cols - 1);

		// if there was more than 1 path found make the function return 1. 
		// if you want to get the number of all possible paths remove this part
		if (result > 1)
		{
			result = 1;
		}

		return result;
	}

	// if didn't continue in any path return zero
	return 0; 
}
