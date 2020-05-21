#include<iostream>
using namespace std;
void inParenthesis(string str)
{
		string s;
		int i=0;
		for( i=0;i<str.length();i++)
			{
				if(str[i] == '(')
					break;
			}
			i++;
		while(str[i] != ')')
			{
				s+=str[i];
				i++;
			}
	cout<<s;

}
int main() {
	string str;
	cin>>str;
	inParenthesis(str);
	return 0;
}
