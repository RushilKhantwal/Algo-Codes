#include <bits/stdc++.h>
using namespace std;

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define ll  long long int
#define vi  vector<ll>

int main() {
    sync;
    ll n;
    cin>>n;

    vi v(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
    }

    double y=0;
    for (int i = 0; i < n; ++i) {
        y += log(v[i]);
    }

    ll ans = ceil(exp(y/n));
    cout << ans;

    return 0;
}
