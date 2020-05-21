#include<bits/stdc++.h>
using namespace std;

int nextGreater(int arr[],int n,int i)
{
    int greater= -1;
    int j=i+1;
    int k =n;
    if(j == n)
            {j=0;}
        while(1)
        {
            if(i == j)
                break;
            if(arr[i]<arr[j])
            {
                greater = arr[j];
                break;
            }
            ++j;
            if(j == n)
                j=0;
            }
      return greater;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
            cin>>arr[i];
    int ans[n];
        for(int i=0;i<n;i++)
                ans[i] = nextGreater(arr,n,i);
        for(int i=0;i<n;i++)
                cout<<ans[i]<<" ";
    return 0;
}
