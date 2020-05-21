#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	stack<int>stk;
	vector<int>v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int k;
	cin >> k;

	int m = INT_MIN;

	for (int i = n - 1; i >= 0; i--)
	{
		stk.push(v[i]);
	}

	int cnt = 0;
	while (!stk.empty())
	{
		int x = stk.top();
		stk.pop();

		++cnt;
		m  = max(x, m);

		if (cnt == k)
		{
			cout << m << " ";
			--cnt;
		}

	}

	return 0;
}
