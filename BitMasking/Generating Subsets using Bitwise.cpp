#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void filterChars(int N, char a[])
{
	int j = 0;
	while (N > 0)
	{
		int last_bit = (N & 1);
		if (last_bit)
		{
			cout << a[j];
		}
		j++;
		N = N >> 1;
	}
	cout << endl;
}

void printSubsets(char a[])
{
	int N = strlen(a);

	for (int i = 0; i < (1 << N); i++)
		filterChars(i, a);

}
int main()
{
	char a[] = {'a', 'b', 'c', '\0'};

	printSubsets(a);
	return 0;
}
