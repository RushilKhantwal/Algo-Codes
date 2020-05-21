#include<bits/stdc++.h>

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


    //1st Line
        for(int i=0;i<n;i++)
                cout<<"*\t";
        cout<<endl;

        //2nd Component
        int k=1;
            for(int i=0;i<n/2;i++)
            {
                for(int j=i;j<n/2;j++)
                        cout<<"*\t";
                //spaces
                    spaces(k);
                     k+=2;
                for(int j=i;j<n/2;j++)
                        cout<<"*\t";

                        cout<<endl;
            }
            //3rd component
            int h = k-4;
            for(int i=0;i<(n/2)-1;i++)
            {
                for(int j=0;j<=i+1;j++)
                        cout<<"*\t";
                    spaces(h);
                    h-=2;
                for(int j=0;j<=i+1;j++)
                        cout<<"*\t";
                    cout<<endl;
            }
            //4th Component
            for(int i=0;i<n;i++)
                cout<<"*\t";
        cout<<endl;

    return 0;
}

