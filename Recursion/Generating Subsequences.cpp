#include <iostream>
#include<vector>
using namespace std;
void generate_subsequence(char* in, char* out, int i, int j)
{
	//Base Case
	if (in[i] == '\0')
	{
		out[j] = '\0';
		cout << out << endl;
		return;
	}

	//Rec Case
	//Include Current Char
	out[j] = in[i];
	generate_subsequence(in, out, i + 1, j + 1);

	//Exclude Current Char

	generate_subsequence(in, out, i + 1, j);
}
int main() {

	char str[] = {'a', 'b', 'c', '\0'};
	char s[10];

	generate_subsequence(str, s, 0, 0);
	return 0;
}
