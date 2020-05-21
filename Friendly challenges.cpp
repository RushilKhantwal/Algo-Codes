#include<bits/stdc++.h>
using namespace std;
int MIN(int arr[],int n,int k)
{
	int moves = 0;
		for(int i=1;i<n;i++)
			{
				if(arr[i]-arr[i-1] != k)
					{
						arr[i] = arr[i-1]+k;
						++moves;
					}

			}
	return moves;
}
int main() {
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	cout<<MIN(arr,n,k);
	return 0;
}
