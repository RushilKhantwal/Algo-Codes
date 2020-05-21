#include<bits/stdc++.h>

using namespace std;
void print(int n)
{
      if(n==1)
          {

            cout<<"*"<<endl;
            return;
          }
      else
      {


            while(--n)
                    cout<<"*\t";

            cout<<endl;
            return print(n-1);
      }
}
int main()
{
    int n;
    cin>>n;

    print(n);
    return 0;
}
