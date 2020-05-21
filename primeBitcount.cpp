// C++ code to find count of numbers
// having prime number of set bits
// in their binary representation in
// the range [L, R]
#include<bits/stdc++.h>
using namespace std;
#include <cmath>

// Function to create an array of prime
// numbers upto number 'n'
vector<int> SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]"
    // and initialize all entries it as false.
    // A value in prime[i] will finally be
    // true if i is Not a prime, else false.
    bool prime[n + 1];
    memset(prime, false, sizeof(prime));
    for(int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == false)

            // Update all multiples of p
            for (int i = p * 2; i < n + 1; i += p)
                prime[i] = true;
    }
    vector<int> lis;

    // Append all the prime numbers to the list
    for (int p = 2; p <=n; p++)
        if (prime[p] == false)
            lis.push_back(p);
    return lis;
}

// Utility function to count
// the number of set bits
int setBits(int n){
    return __builtin_popcount (n);
}

// Driver code
int main ()
{
    int x = 4, y = 8;
    int count = 0;

    // Here prime numbers are checked till the maximum
    // number of bits possible because that the maximum
    // bit sum possible is the number of bits itself.
    vector<int> primeArr = SieveOfEratosthenes(ceil(log2(y)));
    for(int i = x; i < y + 1; i++)
    {
        int temp = setBits(i);
        for(int j=0;j< primeArr.size();j++)
        {if (temp == primeArr[j])
            {count += 1;
            break;
            }
        }
    }
    cout << count << endl;
    return 0;
}
