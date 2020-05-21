#include <bits/stdc++.h>
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

	string str;
	cin >> str;
	reverse(str.begin(), str.end());
	char char_array[str.length() + 1];
	strcpy(char_array, str.c_str());
	int n = pow(2, strlen(char_array));
	char s[n];

	generate_subsequence(char_array, s, 0, 0);
	return 0;
}
