#include<iostream>
using namespace std;
int search(int a[][100], int n, int m, int key)
{
	int endCol = m - 1;
	int endRow = n - 1;
	int k = 0;

	while (endCol >= 0 && k < n)
	{
		if (key == a[k][endCol])
			return 1;
		else if (key < a[k][endCol])
		{
			endCol--;
		}
		else
		{
			k++;
		}
	}
	return  0;
}
int main()
{
	int a[100][100];
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	int key ;
	cin >> key;
	if (search(a, n, m, key))
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
