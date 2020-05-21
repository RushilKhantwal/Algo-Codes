#include<bits/stdc++.h>

using namespace std;

int minSteps(int dp[],int n)
{
    //base case
    if( n == 1)
            return 0;
    //LookUp
                if(dp[n] != 0)
                        return dp[n];
    //rec case
    int x,y,z;
    x=y=z= INT_MAX;
        if(n%3 ==0)
                x= minSteps(dp,n/3);
         if( n%2 == 0)
                y = minSteps(dp,n/2);

         z = minSteps(dp,n-1);

         int ans = min(min(x,y),z)+1;

         return dp[n] = ans;

}
int main()

{
        int x;
        cin>>x;

        int dp[100] = {0};
        dp[1] = 0;

        int res = minSteps(dp,x);

        cout<<endl<<res;
    return 0;
}
