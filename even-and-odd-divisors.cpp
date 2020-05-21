#include<bits/stdc++.h>
using namespace std;
int sum(int n)
{
    int odd=1;
    int even=0;
        for(int i=2;i<=n/2;i++)
            {

             if(n%i == 0)
               {
                   if(i%2 ==0)
                    even+=i;
                else
                        odd+=i;
               }
            }
       if( n%2 ==0)
                even+=n;
       else
                odd+=n;

    return even-odd;
}

int main()
{
    int q;
    cin>>q;
    int n;
    while(q--)
    {
        cin>>n;
        cout<<sum(n)<<endl;;
    }
    return 0;
}
