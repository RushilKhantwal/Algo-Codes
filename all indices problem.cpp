#include<iostream>
using namespace std;
void indices(int arr[], int n, int x)
{
	if (n == 0)
	{
		if (arr[n] == x)
			cout << n << " ";

		return;
	}
	else
	{
		indices(arr, n - 1, x);
		if (arr[n] == x)
		{
			cout << n << " ";
		}
	}
}
int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int x;
	cin >> x;
	indices(arr, n, x);
	return 0;
}
