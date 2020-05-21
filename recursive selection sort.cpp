#include<iostream>
using namespace std;
int minIndex(int a[],int i,int j)
{
	if(i == j)
		return i;
	int k=minIndex(a,i+1,j);

	return (a[i]<a[k])?i:k;
}
void recurSelectionSort(int arr[],int n,int index = 0)
{
	if(index == n)
		return;
	int k = minIndex(arr,index,n-1);
	if(k != index)
		swap(arr[k],arr[index]);

	recurSelectionSort(arr,n,index+1);
}
int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	recurSelectionSort(arr,n);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}
