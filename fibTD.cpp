#include<bits/stdc++.h>

using namespace std;

int fib(int n,int dp[])
{
    //Base Case
    if(n == 1 || n== 0)
    return dp[n] = n;
    //LookUp

    if(dp[n] != 0)
        return dp[n];

    //Rec Case

    return dp[n] = fib(n-1,dp)+fib(n-2,dp);

}
int main()
{
    int dp[100] = {0};

    int x;
    cin>>x;

cout<<"\n"<<fib(x,dp);
    return 0;
}
