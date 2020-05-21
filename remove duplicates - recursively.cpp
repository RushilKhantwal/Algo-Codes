#include<iostream>
#include<cstring>
using namespace std;
void removeDuplicates(char* S)
{

    if (S[0] == '\0')
        return;


    if (S[0] == S[1]) {


        int i = 0;
        while (S[i] != '\0') {
            S[i] = S[i + 1];
            i++;
        }


        removeDuplicates(S);
    }


    removeDuplicates(S + 1);
}
int main() {
	string s;
	cin>>s;
	int n = s.length();
	char str[n+1];
	strcpy(str,s.c_str());

	removeDuplicates(str);
	cout<<str;
	return 0;
}
