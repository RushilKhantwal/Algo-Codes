#include<iostream>
using namespace std;

void zeroes(int n)
{
    for(int i=0;i<n;i++)
        cout<<"0";
}
void ones(int n)
{
    for(int i=0;i<n;i++)
        cout<<"1";
}
int main()
{
    int n;
    cin>>n;
   if(n<3)
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
                cout<<"1";
        cout<<endl;
    }
    else
    {
        //1st Component
            for(int i=1;i<=3;i++)
            {
                    for(int j=0;j<i;j++)
                            cout<<"1";
                                cout<<endl;
            }
          //2nd Component
            for(int i=4;i<=n;i++)
                {
                    cout<<"1";
                        if(i%2 ==0)
                                zeroes(i-2);
                        else
                            ones(i-2);
                        cout<<"1";
                        cout<<endl;


                }
    }
    return 0;
}
