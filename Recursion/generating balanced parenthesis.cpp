#include<bits/stdc++.h>
using namespace std;

void generate_brackets(char* out, int n, int i = 0, int open = 0, int close = 0)
{
	//Base case
	if (i == 2 * n)
	{
		out[i] = '\0';
		cout << out << endl;
		return;
	}

	//rec case

	if (open < n)
	{
		out[i] = '(';
		generate_brackets(out, n, i + 1, open + 1, close);

	}
	if (close < open)
	{
		out[i] = ')';
		generate_brackets(out, n, i + 1, open, close + 1);
	}
	return;
}
int main()
{
	int n;
	cin >> n;
	char output[1000];
	generate_brackets(output, n);
}
