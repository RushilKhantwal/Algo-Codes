
#include<iostream>
#include<set>
using namespace std;
void permute(char* in, int i, set<string> &s)
{
	//Base Case
	if (in[i] == '\0')
	{
		string t(in);
		s.insert(t);
		return;
	}

	//Recursive Case

	for (int j = i; in[j] != '\0'; j++)
	{
		swap(in[i], in[j]);
		permute(in, i + 1, s);
		swap(in[i], in[j]);	// BackTracking Step ,
	}						// we revert  to the original sequence from which
	//recursion tree branched out.

}
int main()
{
	char in[1000];
	cin >> in;
	set<string>s;
	permute(in, 0, s);
	for (auto str : s)
		cout << str << endl;
	return 0;
}
