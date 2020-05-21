#include<iostream>
#include<queue>
using namespace std;
void modify(string str)
{
	queue<char> q;
	int i =0;
	while(i<str.length())
	{
		if(i==0)
			{
				q.push(str[i]);
			}
		else
			{
				if(str[i-1]!=str[i])
					q.push(str[i]);
			}
		i++;
	}
	while(!q.empty())
	{
		char ch=q.front();q.pop();
		cout<<ch;
	}

}
int main() {
	string s;
	cin>>s;

	modify(s);
	return 0;
}
