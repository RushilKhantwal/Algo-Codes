#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int i=1;
    while( n>0 )
    {
        if( ((3*i) +2) % m != 0)
               {
                   cout<<((3*i)+2)<<endl;

                    --n;
                }
          ++i;
    }
}
