#include<bits/stdc++.h>
using namespace std;

int sum(int arr[], int from, int to)
{
	int total = 0;
	for (int i = from; i <= to; i++)
		total += arr[i];
	return total;
}

// for n boards and k partitions
int partition(int arr[], int n, int k)
{
	// base cases
	if (k == 1) // one partition
		return sum(arr, 0, n - 1);
	if (n == 1)  // one board
		return arr[0];

	int best = INT_MAX;

	for (int i = 1; i <= n; i++)
		best = min(best, max(partition(arr, i, k - 1),
		                     sum(arr, i, n - 1)));

	return best;
}
int main()
{
	int k, n;	//k: No. of painters / n: no.of boards
	cin >> k >> n;
	int v[n];

	for (int i = 0; i < n; i++)
		cin >> v[i];

	cout << partition(v, n, k) << endl;

	return 0;
}
