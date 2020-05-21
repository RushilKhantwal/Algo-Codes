#include <iostream>
#include<vector>
using namespace std;

bool sieve[100000001];
int main() {
	sieve[0] = sieve[1] = 1;
	for (int i = 2; i * i <= 100000000; i++)
		if (!sieve[i])
			for (int j = i * i; j <= 100000000; j += i)
				sieve[j] = 1;

	vector<long long>v;
	for (int i = 2; i <= 100000000; i++)
		if (!sieve[i])
			v.push_back(i);

	int N;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> N;
		cout << v[N - 1] << endl;
	}
}
