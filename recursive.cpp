#include<bits/stdc++.h>
using namespace std;

int arraySortedOrNot(int arr[], int n)
{
    if (n == 1 || n == 0)
        return 1;

    if (arr[n - 1] < arr[n - 2])
        return 0;
    return arraySortedOrNot(arr, n - 1);
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
   if(arraySortedOrNot(arr,n))
            cout<<"true";
   else
            cout<<"false";

   return 0;
}
