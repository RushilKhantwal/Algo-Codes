#include<bits/stdc++.h>
using namespace std;

int bin2dec(int n)
{
    int i=0;
    int num = 0;
        while( n != 0)
        {
            if( n%10 == 1)
                num += pow(2,i);

               n = n/10;
               ++i;
        }
    return num;
}
int main()
{
    int n;
    cin>>n;

    cout<<bin2dec(n);
    return 0;
}
