#include<bits/stdc++.h>
using namespace std;

int main()
{
    int min;
    int max;
    int step;

    cin>>min>>max>>step;

    int F;
    F= min;
    int n = max/step+1;
    for(int i=0;i<n;i++)
    {
           int C = (int)(((F-32)*5)/9);
           cout<<F<<"\t"<<C<<endl;
           F=F + step;
    }
}
