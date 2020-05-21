#include<iostream>
using namespace std;
void inverted(int arr[],int a[],int n)
{
    if(n == 0)
        {
          a[arr[n]]=n;
        }
   else
   {
       a[arr[n]]=n;
        inverted(arr,a,n-1);
    }
    cout<<a[n]<<" ";

}
int main()
{
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
                cin>>arr[i];

    //inverted(arr,n-1);
int a[n];
inverted(arr,a,n-1);
 /* for(int i=0;i<n;i++)
           {
               a[arr[i]]=i;
            }
    for(int i=0;i<n;i++)
          cout<<a[i]<<" ";*/
    return 0;
}
