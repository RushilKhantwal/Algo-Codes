#include<iostream>

using namespace std;
void zeroes(int n)
{
    for(int i=0;i<n;i++)
        cout<<"0";
}

int main()
{
    int n;
    cin>>n;
        if(n<2)
            for(int i=0;i<n;i++)
             {
                 for(int j=0;j<=i;j++)
                            cout<<"1";
                     cout<<endl;
             }
           else{
                    for(int i=1;i<=2;i++)
                    {
                         for(int j=1;j<=i;j++)
                            cout<<"1";
                     cout<<endl;
                    }

                   for(int i=3;i<=n;i++)
                   {
                       cout<<i-1;
                           zeroes(i-2);
                       cout<<i-1;

                       cout<<endl;
                   }
           }
    return 0;
}
