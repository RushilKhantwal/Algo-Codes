#include <bits/stdc++.h>
using namespace std;
char keypad[][10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
void generate_names(char* in, char* out, int i, int j)
{
	//Base Case
	if (in[i] == '\0')
	{
		out[j] = '\0';
		cout << out << endl;
		return;
	}

	//Rec Case
	int digit = in[i] - '0';
	for (int k = 0; keypad[digit][k] != '\0'; k++)

	{	out[j] = keypad[digit][k];
		//Fill the remaining part
		generate_names(in, out, i + 1, j + 1);
	}
}
int main() {

	char in[100];
	cin >> in;
	char out[100];
	generate_names(in, out, 0, 0);

	///generate_subsequence(char_array, s, 0, 0);
	return 0;
}
