#include <iostream>
#include<vector>
using namespace std;

void spellings(int n , vector<string>v)
{
	if (n == 0)
		return;
	else
	{

		spellings(n / 10, v);
		cout << v[n % 10] << " ";
	}
}
int main() {
	int n;
	cin >> n;
	vector<string>v{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	spellings(n, v);
	return 0;
}
