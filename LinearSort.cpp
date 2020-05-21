#include<iostream>
using namespace std;

void LinearSort(int arr[],int n)
{
	int one=0,zero=0;

		for(int i=0;i<n;i++)
			{
				if(arr[i] == 0)
					++zero;
				else
					if(arr[i] == 1)
						++one;
			}
	for(int i=0;i<zero;i++)
		cout<<"0 ";

	for(int i=0;i<one;i++)
		cout<<"1 ";
	for( int i = one + zero ;i<n;i++)
			cout<<"2 ";

}
int main() {
	int n;
		cin>>n;
		int arr[n];
			for(int i=0;i<n;i++)
				cin>>arr[i];

			LinearSort(arr,n);
	return 0;
}
