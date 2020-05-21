#include<bits/stdc++.h>
using namespace std;
int index(int arr[], int n, int k)
{
	int ind = 1;
	int sum = 0;
	for (int i = 0; i < k; i++)
		sum += arr[i];


	int curr_sum = sum;

	for (int i = k ; i < n; i++)
	{
		curr_sum += arr[i] - arr[i - k];

		if (curr_sum < sum)
		{
			sum = curr_sum;
			ind = n - k;
		}

	}

	return ind;
}

int main()
{
	int n, k;
	cin >> n >> k;

	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << index(arr, n, k) << endl;



	return 0;
}
