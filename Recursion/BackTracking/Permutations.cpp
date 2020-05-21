
#include<iostream>
using namespace std;
void permute(char* in, int i)
{
	//Base Case
	if (in[i] == '\0')
	{
		cout << in << endl;
		return;
	}

	//Recursive Case

	for (int j = i; in[j] != '\0'; j++)
	{
		swap(in[i], in[j]);
		permute(in, i + 1);
		swap(in[i], in[j]);	// BackTracking Step ,
	}						// we revert  to the original sequence from which
	//recursion tree branched out.

}
int main()
{
	char in[1000];
	cin >> in;
	permute(in, 0);
	return 0;
}
