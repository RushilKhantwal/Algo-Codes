#include <bits/stdc++.h>

using namespace std;

int minSteps(int n)
{
    int dp [100];
    dp[0] = 0;

        for(int i=1;i<=n;i++)
        {
            int temp =0 ;
                if( (i+1)%3 ==0)
                {
                    if((i+1)%2 ==0)
                    {
                         temp= min(dp[((i+1)/3)-1],dp[((i+1)/2)-1]);
                         dp[i]=min(temp,dp[i-1])+1;

                    }
                    else
                            dp[i]= min(dp[((i+1)/3)-1],dp[(i-1)])+1;
                }
              else
              {
                  if((i+1)%2 ==0)
                    {
                         dp[i] = min(dp[((i+1)/2)-1],dp[i-1])+1;

                    }
                    else
                            dp[i]= dp[(i-1)]+1;
              }
        }
      return dp[n-1];
}
int main()
{
    int x;
    cin>>x;

    int res = minSteps(x);
    cout<<"\n"<<res;
    return 0;

}
