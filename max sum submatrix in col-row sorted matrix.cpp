#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int arr[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}

	int suffix[n][m];
	memset(suffix, 0, sizeof(suffix));

	suffix[n - 1][m - 1] = arr[n - 1][m - 1];
	//for last col and row
	for (int i = n - 2; i >= 0; i--)
		suffix[i][m - 1] = suffix[i + 1][m - 1] + arr[i][m - 1];

	for (int i = m - 2; i >= 0; i--)
		suffix[n - 1][i] = suffix[n - 1][i + 1] + arr[m - 1][i];

	for (int i = n - 2; i >= 0; i--) {
		for (int j = m - 2; j >= 0; j--) {
			suffix[i][j] = suffix[i + 1][j] + suffix[i][j + 1] - suffix[i + 1][j + 1] + arr[i][j];
		}
	}

	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < m; j++)
	// 	{
	// 		cout << suffix[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	int max = INT_MIN;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			if (max < suffix[i][j])
				max = suffix[i][j];
			else
				break;
		}
	}

	cout << max << endl;

	return 0;
}
