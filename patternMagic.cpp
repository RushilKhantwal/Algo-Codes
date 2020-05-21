#include<bits/stdc++.h>

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


    //1st Line
        for(int i=0;i<2*n-1;i++)
                cout<<"*";
        cout<<endl;

        //2nd Component
        int k=1;
            for(int i=0;i<((2*n)-2)/2;i++)
            {
                for(int j=i;j<n-1;j++)
                        cout<<"*";
                //spaces
                    spaces(k);
                     k+=2;
                for(int j=i;j<n-1;j++)
                        cout<<"*";

                        cout<<endl;
            }
            //3rd component
            int h = k-4;
            for(int i=0;i<(((2*n)-2)/2)-1;i++)
            {
                for(int j=0;j<=i+1;j++)
                        cout<<"*";
                    spaces(h);
                    h-=2;
                for(int j=0;j<=i+1;j++)
                        cout<<"*";
                    cout<<endl;
            }
            //4th Component
            for(int i=0;i<2*n-1;i++)
                cout<<"*";
        cout<<endl;

    return 0;
}
