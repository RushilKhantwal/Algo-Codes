#include<bits/stdc++.h>

using namespace std;
void spaces(int n)
{
    for(int i=0;i<n;i++)
            cout<<"  ";
}
int main()
{
    int n;
    cin>>n;
    //1st Component
    int k = (2*n)-1;
    for(int i=n;i>0;i--)
    {
        for(int j=n;j>i-1;j--)
                cout<<j<<" ";
            spaces(k);
            k -= 2;
        for(int j= i;j<=n;j++)
                cout<<j<<" ";

                cout<<endl;
    }
   // 2nd component
        for(int i=n;i>0;--i)
                cout<<i<<" ";
    cout<<"0 ";
    for(int i=1;i<=n;i++)
            cout<<i<<" ";
            cout<<endl;
    //3rd Component
    int h = k+2;
        for(int i=n;i>0;i--)
        {
            for(int j = n;j>n-i;--j)
                    cout<<j<<" ";
            spaces(h);
            h+=2;
            for(int j=n-i+1;j<=n;j++)
                    cout<<j<<" ";
            cout<<endl;
        }
    return 0;
}
