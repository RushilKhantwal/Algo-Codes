#include<bits/stdc++.h>

using namespace std;
int minCoins(int n,int coins[],int T,int dp[])
{
    //Base Case
        if(n==0)
                return 0;
        //LookUp
            if(dp[n] != 0 )
                    return dp[n];
           //Rec Case
           int ans = INT_MAX;
            for(int i=0;i<T;i++)
            {
                if(n-coins[i] >= 0)
                {
                    int subprob = minCoins(n-coins[i],coins,T,dp);
                    ans = min(ans,subprob+1);
                }
            }

    return dp[n]=ans;
}
int main()
{
    int dp[100] = {0};
    int coins[] = {1,7,10};
    int N ;
    cin>>N;
    int T = sizeof(coins)/sizeof(int);

    cout<<endl<<minCoins(N,coins,T,dp)<<endl;
        return 0 ;
}
