#include<bits/stdc++.h>
using namespace std;

int search(vector<long double> arr,long double x)
{
    for(int i=0;i<arr.size();i++)
        if(arr[i] == x)
            return 1;
    return 0;
}
int main()
{
    int n;
    cin>>n;
    int x,y;
    cin>>x>>y;
    vector<long double>slope;
    while(n--)
    {
        int i,j;
        cin>>i>>j;
        long double slope1 = ((y-j)/(x-i));
        if(!search(slope,slope1))
            slope.push_back(slope1);
    }
    cout<<slope.size();
    return 0;
}
