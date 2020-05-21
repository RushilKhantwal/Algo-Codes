#include<bits/stdc++.h>
using namespace std;

bool canPlaceCow(int stalls[], int n, int c, int min_sep)
{
	int last_cow = stalls[0];
	int cnt = 1;
	for (int i = 1; i < n; i++)
	{
		if (stalls[i] - last_cow >= min_sep)
		{
			last_cow = stalls[i];
			cnt++;
			if (cnt == c)
				return true;
		}
	}
	return false;
}
int CowSearch(int stalls[], int n, int cows)
{
	int s = 0;
	int e = stalls[n - 1] - stalls[0];

	int ans = 0;

	while (s <= e)
	{
		int mid = (s + e) / 2;

		bool CPC = canPlaceCow(stalls, n, cows, mid);

		if (CPC)
		{
			ans = mid;
			s = mid + 1;
		}
		else
		{
			e = mid - 1;
		}
	}
	return ans;
}
int main()
{
	int n, cows;
	cin >> n >> cows;
	int stalls[n];

	for (int i = 0; i < n; i++)
		cin >> stalls[i];
	sort(stalls, stalls + n);
	cout << CowSearch(stalls, n, cows) << endl;

	return 0;
}
