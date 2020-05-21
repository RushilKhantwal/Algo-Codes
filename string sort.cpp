#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b)
{
	if (strstr(a.c_str(), b.c_str()))
	{
		return a > b;
	}
	else

		return a < b;
}
int main()
{
	int n;
	cin >> n;

	vector<string> vec(n);

	for (int i = 0; i < n; i++)
		cin >> vec[i];

	sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < n; i++)
		cout << vec[i] << endl;

}
