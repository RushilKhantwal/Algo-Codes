#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int power_optimized(int a, int n)
{
	int ans = 1;
	while (n > 0)
	{
		int last_bit = (n & 1);

		if (last_bit)
		{
			ans *= a;
		}
		a *= a;
		n = n >> 1;
	}
	return ans;
}
int main()
{
	int a, n;
	cin >> a >> n;
	cout << power_optimized(a, n) << endl;

	return 0;
}
