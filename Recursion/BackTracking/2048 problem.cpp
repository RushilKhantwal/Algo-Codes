#include<iostream>
using namespace std;
bool ratInMaze(char maze[1000][1000], int soln[][1000], int i, int j, int n, int m)
{
	//base case
	if (i == n and j == m)
	{

		soln[n][m] = 1;

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
	bool rightSuccess = ratInMaze(maze, soln, i, j + 1, n, m);

	//backtracking
	soln[i][j] = 0;

	if (rightSuccess)
		return true;

	soln[i][j] = 1;
	bool downSuccess  = ratInMaze(maze, soln, i + 1, j, n, m);

	//backtracking
	soln[i][j] = 0;
	if (downSuccess)
		return true;

	return false;

}

int main()
{
	char maze[1000][1000];
	int n;
	int m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> maze[i][j];
	int soln[1000][1000] = {0};
	bool ans = ratInMaze(maze, soln, 0, 0, n - 1, m - 1);

	if (!ans)
		cout << "-1";

	return 0;

}
