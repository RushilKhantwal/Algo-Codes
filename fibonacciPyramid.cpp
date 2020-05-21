#include<bits/stdc++.h>
using namespace std;

void printFib(int  t,int n)
{
    int arr[t];
    arr[0] =0;
    arr[1]=1;
        for(int i=2;i<t;i++)
        {
            int a = arr[i-1];
            int b = arr[i-2];
                arr[i] = a + b;
        }
        int k=0;
        for(int i=0; i<n;i++)
        {
                for(int j=0;j<=i;j++)
                {
                    cout<<arr[k++]<<"\t";
                }
        cout<<endl;
        }

}
int main()
{
    int n;
    cin>>n;
    int t= ((n*(n+1))/2);
    printFib(t,n);
}
