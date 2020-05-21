#include<iostream>
using namespace std;
int pairs(int arr[],int n)
{
	int pair=0;
	for(int i=0;i<n;i++)
		{
			for(int j =i+1;j<n;j++)
				{
					if(arr[i]>arr[j])
						++pair;
				}
		}
	return pair;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cout<<pairs(arr,n)<<endl;

	}
	return 0;
}
