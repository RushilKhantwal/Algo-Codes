#include <bits/stdc++.h>
using namespace std;
char keypad[][10] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void generate_names(char* in, char* out, int i, int j)
{
	//Base Case
	if (in[i] == '\0')
	{
		out[j] = '\0';
		cout << out << "\n";
		return;
	}

	//Rec Case
	int digit = in[i] - '0';
	if (digit == 0)
	{
		generate_names(in, out, i + 1, j);
	}

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
	// int n = 1;
	// for (int i = 0; in[i] != '\0'; i++)
	// {
	// 	if (in[i] != '1' or in[i] != '0')
	// 	{
	// 		n *= str[in[i] - '0'];
	// 	}
	// }
	// cout << endl << n;
	//generate_subsequence(char_array, s, 0, 0);
	return 0;
}
