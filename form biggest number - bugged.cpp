#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	int q;
	cin >> q;

	while (q--)
	{
		int n;
		cin >> n;
		vector <string> vec (n);

		for (int i = 0; i < n; i++)
		{
			cin >> vec[i];
		}
		sort(vec.rbegin(), vec.rend());
		string str;
		for (int i = 0; i < n; i++)
			str += vec[i];

		cout << str << endl;

	}
	return 0;
}
