#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll power_optimized(ll a, ll n, ll c)
{
	int ans = 1;
	while (n > 0)
	{
		int last_bit = (n & 1);

		if (last_bit)
		{
			ans = (ans * a) % c;
		}
		a = (a * a) % c;
		n = n >> 1;
	}
	return ans % c;
}
int main()
{
	ll a, n, c;
	cin >> a >> n >> c;
	cout << power_optimized(a, n, c)  << endl;

	return 0;
}
