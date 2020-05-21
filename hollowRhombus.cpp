#include<iostream>
using namespace std;
void spaces(int k)
{
    for(int i=0;i<k;i++)
            cout<<" ";
}
int main()
{
    int n;
    cin>>n;
        //1st Component
            spaces(n-1);
            for(int i=0;i<n;i++)
                    cout<<"*";
            cout<<endl;

            //2nd Component
         int k = n-2;
                    for(int i=0;i<n-2;i++)
                    {
                        spaces(k);
                            cout<<"*"<<"   "<<"*"<<endl;
                          k-=1;
                    }
                 //3rd Component

            for(int i=0;i<n;i++)
                    cout<<"*";
    return 0 ;
}
