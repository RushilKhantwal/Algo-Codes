#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll nC2(ll n);
int main()
{
    ll a,b;
    cin>>a>>b;
    ll high = nC2(a-b+1);
    ll low = (b - a % b) * (nC2(a/b)) + (a % b) * (nC2(a/b + 1));
    cout<<low<<" "<<high<<endl;
    return 0;
}

ll nC2(ll n)
{
    if (n==0)
            return 1;
    else
        return (n*(n-1))/2;
}

