#include<bits/stdc++.h>
using namespace std;
long long inverse( long long n)
{
        int j=0;
        int i=0;
        long long inv=0;
        while(n != 0)
        {
              ++j;
              i=(n%10) - 1;
            inv += ((pow(10,i))*j);

                 n /= 10;
        }

        return inv;
}
int main()
{
    long long n;
    cin>>n;
    long long res = inverse(n);


        if( res == n)
                cout<<"true";
        else
                cout<<"false";
    return 0;
}
