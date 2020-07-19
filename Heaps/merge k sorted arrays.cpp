#include<iostream>
#include<queue>
using namespace std;

int main() {
	priority_queue<int,vector<int>,greater<int>>pq;

	int k;cin>>k;
	int n;cin>>n;

	for(int i=0;i<n*k;i++)
	{
		int x;
		cin>>x;
		pq.push(x);
	}

	while(!pq.empty())
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}
	return 0;
}
