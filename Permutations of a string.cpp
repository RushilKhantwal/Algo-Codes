#include<bits/stdc++.h>
using namespace std;
int factorial(int n)
{
    return (n ==1||n==0)? 1:n*factorial(n-1);
}
void permute(string a, int l, int r)
{
    // Base case
    if (l == r)
        cout<<a<<" ";
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {

            // Swapping done
            swap(a[l], a[i]);

            // Recursion called
            permute(a, l+1, r);

            //backtrack
            swap(a[l], a[i]);
        }
    }
}
int main()
{
    string str;
    cin>>str;
    int n=str.length();
    cout<<factorial(n)<<endl;
 permute(str,0,n-1);

}
