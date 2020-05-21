#include<bits/stdc++.h>

#define ll long long int
#define p 1e9+7
using namespace std;
ll nCrModp(ll n, ll r )
{
    if (r > n - r)
        r = n - r;


    ll C[r + 1];
    memset(C, 0, sizeof(C));

    C[0] = 1;


    for (int i = 1; i <= n; i++) {


        for (int j = min(i, r); j > 0; j--)
                C[j] = (C[j] + C[j - 1]) % p;
    }
    return C[r];
}
int main()
{
    ll n,r;
    cin>>n>>r;
    cout<<nCrModp(n,r);
    return 0;
}
