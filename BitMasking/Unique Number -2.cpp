#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
	int n;
	cin >> n;
	int no;
	int res  = 0;
	int a[100000];
	for (int i = 0; i < n; i++)
	{
		cin >> no;
		a[i] = no;
		res = res ^ no;
	}

	int temp = res;
	int pos = 0;

	while ((temp & 1) != 1)
	{
		pos++;
		temp = temp >> 1;
	}
	int mask = (1 << pos);

	int x = 0, y = 0;
	for (int i = 0; i < n; i++)
	{
		if ((a[i]&mask) > 0)
			x = x ^ a[i];
	}
	y = res ^ x;

	cout << min(x, y) << " " << max(x, y) << endl;
	return 0;
}
