#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll sum(int n,int a,int d)
{
    ll s = ((n*((2*a)+((n-1)*d)))/2);
    return s;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,d;
        cin>>n>>a>>d;
        cout<<sum(n,a,d)<<endl;

    }
    return 0;
}
