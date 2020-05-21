#include<iostream>
using namespace std;
bool check(int arr[],int a[],int n)
{

    int res[n];
    for(int i=0;i<n;i++)
    {
        res[arr[i]]=i;
    }
    for(int i=0;i<n;i++)
    {
            if(a[i] != res[i])
                return false;
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    int arr[n],a[n];
    for(int i=0;i<n;i++)
            cin>>arr[i];
    for(int i=0;i<n;i++)
            cin>>a[i];

    check(arr,a,n)?cout<<"true":cout<<"false";
    return 0;
}
