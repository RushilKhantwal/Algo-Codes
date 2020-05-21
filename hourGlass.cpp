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
    int k=0;
        //1st Component
            for(int i=n;i>0;i--)
            {
                spaces(k);
                                for(int j=i;j>0;j--)
                                                cout<<j<<" ";
                cout<<"0 ";
                                for(int j=1;j<=i;j++)
                                                cout<<j<<" ";
                ++k;
                                cout<<endl;
            }
           //2nd component
              spaces(n);
                cout<<"0\n";
             //3rd component
             int h= k-1;
                    for(int i=n;i>0;i--)
            {
                    spaces(h);
                  for(int j=n-i+1;j>0;j--)
                                    cout<<j<<" ";

                cout<<"0 ";
                                for(int j=1;j<n-i+2;j++)
                                                cout<<j<<" ";
                --h;
                                cout<<endl;
            }
    return 0;

}
