
#include<iostream>
#include<math.h>
using namespace std;

bool canPlace(int mat[][9], int i, int j, int n, int number)
{
	for (int x = 0; x < n; x++)
	{
		//Row and Column Check
		if (mat[x][j] == number or mat[i][x] == number)
		{return false;}
	}
	int rn = sqrt(n);
	int sx = (i / rn) * rn;
	int sy = (j / rn) * rn;

	for (int x = sx; x < sx + 3; x++)
	{
		for (int y = sy; y < sy + 3; y++)
		{
			if (mat[x][y] == number)
			{
				return false;
			}
		}
	}
	return true;
}

bool solveSudoku(int mat[9][9], int i, int j , int n)
{
	//Base case

	if (i == n)
	{
		//Print matrix
		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < n; y++)
			{
				cout << mat[x][y] << " ";

			}
			cout << endl;
		}
		cout << endl;
		return true;
	}

	// Case Row end
	if (j == n)
	{
		return solveSudoku(mat, i + 1, 0, n);

	}
	//Skip Pre-filled Cells
	if (mat[i][j] != 0)
	{
		return solveSudoku(mat, i, j + 1, n);
	}

	//Rec Case
	//Fill the current cell w Possible Options

	for (int number = 1; number <= n; number++)
	{
		if (canPlace(mat, i, j, n, number))
		{
			//Assume

			mat[i][j] = number;

			bool couldWeSolve  = solveSudoku(mat, i, j + 1, n);
			if (couldWeSolve)
				return true;
		}
	}
	//Backtrack here
	mat[i][j] = 0;

	return false;
}

int main()
{
	int n;
	cin >> n;
	int mat[9][9];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mat[i][j];

	solveSudoku(mat, 0, 0, n);

	return 0;
}
