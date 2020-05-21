#include <iostream>
#include<string>
using namespace std;
bool isCB(long long sub)
{
	//int flag=0;
	//cout<<sub<<" ";
	if (sub == 0 || sub == 1)
	{
		//cout<<endl;
		return false;
	}
	int prime[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	for (int i = 0; i < 10; i++)
	{
		if (sub == prime[i])
		{
			//flag=1;
			//cout<<flag<<" "<<sub<<endl;
			return true;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (sub % prime[i] == 0)
		{
			//cout<<endl;
			return false;
		}
	}
	//flag=1;
	//cout<<flag<<" "<<sub<<endl;
	return true;
}



bool isValid(bool visited[17], string str, int start, int end)
{
	//cout<<"isValid starts ";
	//cout<<str<<" ";
	//cout<<"("<<start<<","<<end<<")"<<endl;
	/*for(int j=start;j<end;j++)
	{
	    cout<<str[j];
	}
	cout<<endl;
	*/
	//int flag=0;
	for (int i = start; i < end; i++)
	{
		if (visited[i])
		{
			//flag=1;
			//cout<<"("<<start<<","<<end<<") "<<flag<<endl;
			return false;
		}
	}
	//cout<<"isValid starts ";
	//cout<<str<<" ";
	//cout<<"("<<start<<","<<end<<") "<<flag<<endl;
	return true;
}



int main()
{
	int N, cnt = 0;
	cin >> N;
	string str;
	cin >> str;
	//getline(cin,str);
	//cout<<str<<" dfghj";
	bool visited[str.length()];
	for (int k = 0; k < str.length(); k++)
	{
		visited[k] = false;
	}
	for (int len = 1; len <= str.length(); len++)
	{
		for (int start = 0; start <= str.length() - len; start++)
		{
			//cout<<"HJl"<<start;

			int end = start + len;
			//cout<<start<<","<<end<<endl;
			string sub = str.substr(start, len);
			//cout<<sub<<endl;
			if (isCB(stoll(sub)) && isValid(visited, sub, start, end))
			{
				//cout<<"FGHJ";
				cnt++;
				//cout<<sub<<endl;
				for (int i = start; i < end; i++)
				{
					visited[i] = true;
				}
			}
		}
	}
	cout << cnt;

}
