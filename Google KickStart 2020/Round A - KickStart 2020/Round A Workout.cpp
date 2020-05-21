
#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define int long long
const int N = 1e5+5;
int n,k;
int a[N];
bool check(int d)
{
    int reqdAdditional = 0;
    for(int i=1; i+1 <= n; i++)
            reqdAdditional += (a[i+1] - a[i] -1)/d;

        if(reqdAdditional<= k)
                return true;
     return false;
}
int binSearch(int lo,int hi)
{
    while(lo<hi)
    {

        int mid = (lo + hi)/2;
            if(check(mid))
                hi= mid;
            else
                lo = mid+1;
    }
    return lo;
}
int32_t main()
{
    int t;
    cin>>t;
    int tc=0;
    while(t--)
    {
        tc++;
            cin>>n>>k;
            for(int i=1;i<=n;i++)
                    cin>>a[i];
            int ans = binSearch(1,1e9);
            cout<< "Case #" << tc << ": " << ans << endl;
    }
    return 0;
}
