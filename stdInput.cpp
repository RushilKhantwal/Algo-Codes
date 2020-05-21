#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int arraySortedOrNot(int arr[], int n,int M)
{

    if ( n == 0)
    {
            if(arr[n] == M)
                return 1;

           return 0;
    }



    if (arr[n - 1] == M)
        return 1;

    return arraySortedOrNot(arr, n - 1,M);
}
int main()
{
    int n;
    cin>>n;
    int arr[n];

        for(int i=0;i<n;i++)
                cin>>arr[i];

                int M;
                cin>>M;
        if(arraySortedOrNot(arr,n,M))
                cout<<"true";
        else
                cout<<"false";
    return 0;
}
