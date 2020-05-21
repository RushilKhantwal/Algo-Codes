#include<iostream>
using namespace std;
int count = 0;
bool ratInMaze(char maze[10][10], int soln[][10], int i, int j, int n, int m, int &count)
{
	//base case
	if (i == n and j == m)
	{
		soln[n][m] = 1;
		count++;
		//print solution
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= m; j++)
				cout << soln[i][j] << " ";
			cout << endl;
		}
		cout << endl;

		return true;
	}
	//If rat leaves the grid
	if (i > n or j > m)
		return false;
	if (maze[i][j] == 'X')
		return false;
	//we assume that a path exists
	soln[i][j] = 1;
	bool rightSuccess = ratInMaze(maze, soln, i, j + 1, n, m, count);
	bool downSuccess  = ratInMaze(maze, soln, i + 1, j, n, m, count);

	//backtracking
	soln[i][j] = 0;
	if (rightSuccess or downSuccess)
		return true;

	return false;

}

int main()
{
	char maze[10][10] = { "0000", "00X0", "000X", "0X00"};
	int n = 4, m = 4;
	int soln[10][10] = {0};
	bool ans = ratInMaze(maze, soln, 0, 0, n - 1, m - 1, count);

	if (!ans)
		cout << "No Path Exists!";
	else
		cout << endl << count;

	return 0;

}
