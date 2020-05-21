#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
        int j;
        for(int i=1;i<=n;i++)
        {
                for( j=1;j<=i;j++)
                        cout<<j<<" ";
                if(j<=n)
                {
                    for(int k=j-1;k<n;k++)
                            cout<<"* ";
                }
                cout<<endl;
        }
    return 0;
}
