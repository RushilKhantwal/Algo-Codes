#include <bits/stdc++.h>
using namespace std;

// str : Stores input string
// n : Length of str.
// curr : Stores current permutation
// index : Index in current permutation, curr
void printSubSeqRec(string str, int n,
                    int index = -1, string curr = "")
{
	// base case
	if (index == n)
		return;

	cout << curr << "\n";
	for (int i = index + 1; i < n; i++) {

		curr += str[i];
		printSubSeqRec(str, n, i, curr);

		// backtracking
		curr = curr.erase(curr.size() - 1);
	}
	return;
}
// Driver code
int main()
{
	string str;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> str;

		printSubSeqRec(str, str.size());
	}
	return 0;
}
