#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;

	int arr[n][m];
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < n; j++)
	// 		cout << arr[i][j] << " ";
	// 	cout << endl;
	// }



	int q;
	cin >> q;

	int sum = 0;
	int pre[n][m];

	memset(pre, 0, sizeof(pre));


	pre[0][0] = arr[0][0];

	// Filling first row and first column
	for (int i = 1; i < m; i++)
		pre[0][i] = pre[0][i - 1] + arr[0][i];
	for (int i = 0; i < n; i++)
		pre[i][0] = pre[i - 1][0] + arr[i][0];

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++)
			pre[i][j] = pre[i - 1][j] + pre[i][j - 1]
			            - pre[i - 1][j - 1] + arr[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << pre[i][j] << " ";
		cout << endl;
	}

	while (q--)
	{
		int tli, tlj, rbi, rbj;
		cin >> tli >> tlj >> rbi >> rbj;
		int res = pre[rbi][rbj];

		// Remove elements between (0, 0) and (tli-1, rbj)
		if (tli > 0)
			res = res - pre[tli - 1][rbj];

		// Remove elements between (0, 0) and (rbi, tlj-1)
		if (tlj > 0)
			res = res - pre[rbi][tlj - 1];

		// Add aux[tli-1][tlj-1] as elements between (0, 0)
		// and (tli-1, tlj-1) are subtracted twice
		if (tli > 0 && tlj > 0)
			res = res + pre[tli - 1][tlj - 1];

		cout << res << endl;
	}

	return 0;
}
