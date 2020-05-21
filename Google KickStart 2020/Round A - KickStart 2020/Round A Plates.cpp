
#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define int long long
int n,k,p;

const int N = 51;
const int P = 51*30;
int a[N][31],pref[N][31];
int cache[N][P];
int rec(int idx,int taken)
{
    if(taken == p)
            return 0;
    if(idx >n || taken >p)
            return -1e9;

    if(cache[idx][taken] != -1)
                    return cache[idx][taken];

    int ans =-1e9;

        for(int i=0;i<=k;i++)
                ans = max(ans,pref[idx][i]+rec(idx+1,taken+i));

        return cache[idx][taken] = ans;
}
int32_t main()
{
    IOS;
    int t;
    cin>>t;
    int tc = 0;
    while(t--)
    {
        tc++;
        cin>>n>>k>>p;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>a[i][j];
                pref[i][j]= pref[i][j-1]+a[i][j];
            }
        }
        memset(cache,-1,sizeof(cache));
            int ans = rec(1,0);

            cout<<"Case #" << tc<< ": " << ans<<endl;
    }
    return 0;
}
