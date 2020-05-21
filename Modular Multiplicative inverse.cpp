#include<iostream>
#define ll long long int
using namespace std;
ll m 1000007;
// To find GCD of a and b
ll gcd(ll a, ll b);

// To compute x raised to power y under modulo m
ll power(ll x, ll y, ll m);
// Function to find modular inverse of a under modulo m
// Assumption: m is prime
void modInverse(ll a, ll m)
{
    ll g = gcd(a, m);
    if (g != 1)
        return;
    else
    {
        // If a and m are relatively prime, then modulo inverse
        // is a^(m-2) mode m
        cout << power(a, m-2, m);
    }
}

// To compute x^y under modulo m
ll power(ll x, ll ll y, ll m)
{
    if (y == 0)
        return 1;
    int p = power(x, y/2, m) % m;
    p = (p * p) % m;

    return (y%2 == 0)? p : (x * p) % m;
}

// Function to return gcd of a and b
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
int main()
{
    ll n;
    cin>>n;
    modInverse(n,m);
    return 0;
}
