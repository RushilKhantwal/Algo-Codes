#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector <int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];

	int q;
	cin>>q;
	while(q--)
	{
		int x;
		cin>>x;
		if(binary_search(arr.begin(),arr.end(),x))
			{
				vector<int>::iterator low = lower_bound(arr.begin(),arr.end(),x);
	    		vector<int>::iterator hi = upper_bound(arr.begin(),arr.end(),x);
				cout<<(low- arr.begin())<<" "<<(hi - arr.begin())-1<<endl;
			}
		else
			cout<<"-1 -1"<<endl;
	}
	return 0;
}
