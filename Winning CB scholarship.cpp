#include<bits/stdc++.h>
using namespace std;

// bool isPossible();
int scholarships(int n, int m, int x, int y)
{
	int s = 0;
	int e = n;
	if (m < x)
		return -1;
	int ans = 0;
	while (s <= e)
	{
		int mid = (s + e) / 2;

		if (mid * x <= m + (n - mid)*y)
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

	int n, m, x, y;

	cin >> n >> m >> x >> y;

	cout << scholarships(n, m, x, y);



	return 0;
}
