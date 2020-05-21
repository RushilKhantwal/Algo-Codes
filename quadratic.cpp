#include<bits/stdc++.h>

using namespace std;

int main()
{
    int A,B,C;
    cin>>A>>B>>C;

    int D = ((B*B) - (4*A*C));
    int x1,x2;
    if( D >0 )
            {
                x1 =  (((-B) - sqrt(D))/(2*A));
                x2 =  (((-B) + sqrt(D))/(2*A));
                cout<<"Real and Distinct"<<endl;
                    if(x1<x2)
                        cout<<x1<<" "<<x2;
                    else
                        cout<<x2<<" "<<x1;
            }
      if(D == 0)
      { x1 = x2 = ((-B)/2*A);
          cout<<"Real and Equal"<<endl;
          cout<<x1<<" "<<x2;

      }
      if(D<0)
            cout<<"Imaginary"<<endl;

     return 0;
}
