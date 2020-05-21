#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
            cin>>arr[i];
    int i =0;
        while(i<=n-i+1)
        {
            reverse(arr+i,arr+(n-i));
           ++i;
        }
        for(int i =0;i<n;i++)
            cout<<arr[i]<<" ";
    return 0;
}
