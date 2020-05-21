#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// A simple method to evaluate Euler Totient Function
int phi(unsigned int n)
{
    unsigned int result = 1;
    for (int i = 2; i < n; i++)
        if (gcd(i, n) == 1)
            result++;
    return result;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int l,r;
		cin>>l>>r;
		int sum =0;
		for(int i=l;i<=r;i++)
			sum+=phi(i);
		cout<<sum;
	}
	return 0;
}
