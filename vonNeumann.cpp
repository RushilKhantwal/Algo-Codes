#include<bits/stdc++.h>
using namespace std;

int bin2dec(int x)
{ int ans = 0;
   int i=0;
     while(x != 0 )
     {
         if(x%10 == 1)
            ans += pow(2,i);
         x= x/10;
         ++i;
     }
     return ans;
}
int main()
{

    int n;
    cin>>n;

    vector <int> arr(n);

    for(int i=0;i<n;i++)
            cin>>arr[i];

    for(int i=0;i<n;i++)
    {
            cout<<bin2dec(arr[i])<<endl;
    }
}
