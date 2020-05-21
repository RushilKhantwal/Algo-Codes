#include<iostream>
using namespace std;
int getMax(int arr[],int n,int i)
{
	int m = arr[i];
while(--n)
{   ++i;
    m=max(m,arr[i]);
}
	return m;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
            cin>>arr[i];
    for(int i=0;i+k<=n;i++)
            cout<<getMax(arr,k,i)<<" ";

    return 0;
}
