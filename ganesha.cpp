#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    //1st component
    cout<<"*";
    for(int i=1;i<=(n-3)/2;i++)
            cout<<" ";
    for(int i=1;i<=(n+1)/2;i++)
    {
        cout<<"*";
    }
    cout<<endl;
    //2nd component
    for(int rows =1;rows<=(n-3)/2;rows++)
           {

            cout<<"*";
        //spaces
            for(int i=1;i<=(n-3)/2;i++)
                    cout<<" ";
            cout<<"*"<<endl;
           }
      //3rd component
            for(int i=1;i<=n;i++)
                    cout<<"*";
            cout<<endl;

            //4th component
            for(int rows =1;rows<=(n-3)/2;rows++)
            {

                //spaces
                    for(int i=0;i<=(n-3)/2;i++)
                        cout<<" ";

                        cout<<"*";
                        //spaces
                            for(int i=1;i<=(n-3)/2;i++)
                                    cout<<" ";
                            cout<<"*"<<endl;
            }
           //5th component
                for(int i=1;i<=(n+1)/2;i++)
                        cout<<"*";
                    //spaces
                        for(int i = 1;i<=(n-3)/2;i++)
                                cout<<" ";
                        cout<<"*";
    return 0;
}
