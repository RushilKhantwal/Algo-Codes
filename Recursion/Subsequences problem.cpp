#include<bits/stdc++.h>
using namespace std;
void generate_substring(char* s_input, char* s_output, int i, int j) {
	//base case
	if (s_input[i] == '\0') {
		s_output[j] = '\0';
		cout << s_output << " ";
		return;
	}
	//rec case
	//2. exclude s_out[i]
	generate_substring(s_input, s_output, i + 1, j);
	//1. include s_in[i]
	s_output[j] = s_input[i];
	generate_substring(s_input, s_output, i + 1, j + 1);
}
int main() {
	char s_input[100], s_output[100];
	cin >> s_input;
	generate_substring(s_input, s_output, 0, 0);
	int i;
	for (i = 0; s_input[i] != '\0'; i++) {

	}
	cout << endl << (1 << i);
	return 0;
}
