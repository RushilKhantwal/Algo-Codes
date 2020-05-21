#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int Min(int arr[],int n,int w)
{
	vector <int> minimum;
	int ans = INT_MAX;
	int weight=0;
	int cost=0;
	for(int i=1;i<n;i++)
		{
			weight =0;
			cost = 0;
			for(int j=i;j<n;j++)
				{
					if(weight+j<= w)
			 		{
						weight+=j;
						cost+=arr[j];
			 		}

					if(weight == w)
					minimum.push_back(cost);
				}

		}
		if(minimum.size() == 0)
			return ans = -1;
		for(int i=0;i<minimum.size();i++)
			{
				ans = min(ans,minimum[i]);
			}

	return ans;
}
int main() {
	int n,w;
	cin>>n>>w;
	int arr[n+1];
	arr[0]=0;
	for(int i=1;i<n+1;i++)
		cin>>arr[i];
	cout<<Min(arr,n+1,w);
	return 0;
}
