#include<iostream>
using namespace std;
bool isSafe(int board[10][10], int i, int j, int n)
{
	//You can check column

	for (int row = 0; row < i; row++)
	{
		if (board[row][j] == 1)
		{
			return false;
		}
		int x = i;
		int y = j;

		while (x >= 0 and y >= 0)
		{
			if (board[x][y] == 1)
			{
				return false;
			}
			x--;
			y--;
		}
		x = i;
		y = j;
		while (x >= 0 and y < n)
		{
			if (board[x][y] == 1)
			{
				return false;
			}
			x--;
			y++;
		}

	}
	return true;
}

bool solveNQueen(int board[10][10], int i , int n)
{
	//Base Case

	if (i == n)
	{
		//You have successfully places queens in rows(0 ... n-1)

		//Print Board

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == 1)
					cout << "Q";
				else
					cout << "-";
			}
			cout << endl;
		}

		return true;
	}

	//Recursive Case
	for (int j = 0; j < n; j++)
	{
		if (isSafe(board, i, j, n))
		{
			//Place the Queen

			board[i][j] = 1;

			bool nextQueen = solveNQueen(board, i + 1, n);

			if (nextQueen)
				return true;
		}
		//Reaching here means that we couldnt safely put queen at (i,j)th position
		board[i][j] = 0;

	}
	return false;
}
int main()
{
	int n;
	cin >> n;

	int board[10][10] = {0};

	solveNQueen(board, 0, n);

	return 0;
}
