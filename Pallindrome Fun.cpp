#include<iostream>
#include<stack>
using namespace std;
bool isPallindrome(string str)
{
	stack<char> stk;

	for(int i=0;i<=(str.length())/2;i++)
		stk.push(str[i]);

	for(int j=(str.length())/2;j<str.length();j++)
	{
		char ch = stk.top();
		stk.pop();
		if(ch != str[j])
			return false;
	}
	return true;
}
int main() {
	string str;
	cin>>str;
	int t;
	cin>>t;
	while(t--)
	{
		int i,j;
		cin>>i>>j;
		char ch;
		cin>>ch;
		str[i]=str[j]=ch;
		if(isPallindrome(str))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
