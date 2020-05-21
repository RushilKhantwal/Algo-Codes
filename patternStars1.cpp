#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
int j;
    for(int i=n;i>0;i--)
    {

        for( j=1;j<=i;j++)
                {
                    cout<<j<<" ";
                }
           if(j<=n)
           {
               for(int k=n+1;k>j;--k)
                    cout<<"* ";
               for(int k=n;k>j;--k)
                        cout<<"* ";
           }

        cout<<endl;
    }
    return 0;
}
