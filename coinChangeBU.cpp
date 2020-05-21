#include<bits/stdc++.h>

using namespace std;
int minCoins(int n,int coins[],int T)
{

    int dp[100] = {0};
    dp[0] = 0;

    for(int i=1;i<=n;i++)
    {
        int ans = INT_MAX;
        for(int j=0;j<T;++j)
        {
                if(i-coins[j] >=0)
                {
                   ans = min(ans,dp[i-coins[j]]+1);
                }

        }
      dp[i] = ans;
    }
  return dp[n];
}
int main()
{
    int coins[] = {1,7,10};
    int T = sizeof(coins)/sizeof(int);

       int n ;
       cin>>n;

       cout<<"\n"<<minCoins(n,coins,T);

    return 0;
}
