#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    string s;
    cin>>str>>s;
    reverse(s.begin(),s.end());
        if( s == str)
                cout<<"true";
        else
                cout<<"false";
    return 0;
}
