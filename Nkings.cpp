#include <iostream>
using namespace std;

long long unsigned int count( int n,long long unsigned int  dp[])
{
    if(n==0 || n==1)
    {
        return 1;
    }
    if(n==2 || n==3)
    {
        return 0;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    dp[n]=((n+1)*count(n-1,dp)) - ((n-2)*count(n-2,dp)) -((n-5)*count(n-3,dp))+((n-3)*count(n-4,dp));
    return dp[n];
}
int main() {
    int n;
    cin>>n;
    long long unsigned int dp[2*n];
    for(int i=0;i<2*n;i++)
    {
        dp[i]=-1;
    }
    cout<<count(n,dp);
}

