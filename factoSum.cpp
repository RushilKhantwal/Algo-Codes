
#include<iostream>
using namespace std;

int main() {
	long long n;
	cin>>n;
		long long arr[n];
		long long ans[n];
    long long factorial[1000]={1};
    factorial[0] = 1%107;
		for(auto i=0;i<n;i++)
			cin>>arr[i];

        for(auto i=1;i<=1000;i++)
            factorial[i] = ((i*factorial[i-1])%107);

            for(auto i=0;i<n;i++)
                    ans[i]= factorial[arr[i]];


	long long sum = 0;
		for(auto i=0;i<n;i++)
			sum += ans[i];

		cout<<sum;

	return 0;
}
