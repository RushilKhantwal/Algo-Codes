#include<iostream>
#define ll long long int
using namespace std;
int main() {
	int t;
	cin>>t;
	int q;
	int n;
	while(t--)
	{

	cin>>n;cin>>q;
	int arr[100000010];
	for(int i=0;i<n;i++)
			cin>>arr[i];

	int freq[100000010];
	for(int i=0;i<n;i++)
		freq[arr[i]]++;

	while(q--)
	{
		ll x;
		cin>>x;
		cout<<freq[x]<<endl;

	}
	}
	return 0;
}
