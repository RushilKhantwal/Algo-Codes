#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>v, int n, int m, int curr_min)
{
	int studentsUsed = 1;
	int pages_reading = 0;


	for (int i = 0; i < n; i++)
	{
		if (pages_reading + v[i] > curr_min)
		{
			studentsUsed++;
			pages_reading = v[i];

			if (studentsUsed > m)
			{
				return false;
			}
		}
		else
		{
			pages_reading += v[i];
		}
	}
	return true;
}
int findPages(vector<int>v, int n, int m)
{
	if (n < m)
	{
		return -1;
	}
	int sum = 0;

	for (int i = 0; i < n; i++)
		sum += v[i];

	int s = v[n - 1];
	int e = sum;
	int ans = INT_MAX;

	while (s <= e)
	{
		int mid = (s + e) / 2;

		if (isPossible(v, n, m, mid))
		{
			ans = min(ans, mid);
			e = mid - 1;
		}
		else
		{
			s = mid + 1;
		}


	}
	return ans;
}

int main()
{
	int t;
	cin >> t;
	int m, n; 	//n: no. of books , m: no. of students
	while (t--)
	{
		cin >> n >> m;

		vector<int> v(n);

		for (int i = 0; i < n; i++)
			cin >> v[i];

		cout << findPages(v, n, m) << endl;

	}



	return 0;
}
