#include<iostream>

using namespace std;

void spaces(int k)
{
    for(int i=0;i<k;i++)
            cout<<"\t";
}

int main()
{
    int n;
    cin>>n;
    int h;

        if(n%2 ==0)
             h = n+1;
        else
             h = n+2;

        for(int i=0;i<n-1;i++)
            {
                for(int j=1;j<=i+1;j++)
                        cout<<j<<"\t";
                    spaces(h);
                    h-=2;
                for(int j=i+1;j>0;j--)
                        cout<<j<<"\t";
                    cout<<endl;
            }

        for(int i = 1;i<n;i++)
            cout<<i<<"\t";

        cout<<n<<"\t";
        for(int i=n-1;i>0;--i)
            cout<<i<<"\t";

    return 0;
}
