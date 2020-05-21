#include<bits/stdc++.h>
using namespace std;
bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
	return (a.second < b.second);
}
int activitySelection(vector<pair<int, int>> v)
{
	sort(v.begin(), v.end(), compare);
	int count = 1;
	int j = 0;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i].first >= v[j].second)
		{
			count++;
			j = i;
		}
	}
	return count;
}
int main() {
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
		vector<pair<int, int>>v;
		int x, y;
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			v.push_back(make_pair(x, y));
		}

		cout << activitySelection(v) << endl;

	}
	return 0;
}
