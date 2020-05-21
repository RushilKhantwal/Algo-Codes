#include<bits/stdc++.h>
using namespace std;
#define IOS  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define int long long
const int N = 1e5+5;
int32_t main()
{

    IOS;
    int t;
    cin>>t;
    int n,b;
    int a[N];
    int tc = 0;
    while(t--)
    {
        cin>>n>>b;
            for(int i =1; i<= n;i++)
                    cin>>a[i];
            sort(a+1,a+n+1);
            int ans =0;
            for(int i=1; i<= n;i++)
            {

                if(b >= a[i])
                {
                    ans++;
                    b -= a[i];

                }
                cout<< "Case #" <<tc<<": "<< ans<<endl;
            }
    }
    return 0;
}
