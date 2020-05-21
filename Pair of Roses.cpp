#include<bits/stdc++.h>
using namespace std;
vector<long long> pairs(vector<long long>arr,int n,int target)
{
    vector <long long >ans;
    ans.push_back(100000000);
    ans.push_back(0);
    sort(arr.begin(), arr.end());
	int left = 0, right = n- 1;
	while(left < right){
		if(arr[left] + arr[right] == target){
                if( abs(arr[left]-arr[right])<abs(ans[0]-ans[1]))
               {        ans[0]=arr[left];
                        ans[1]=arr[right];
                }
			left++;
			right--;
		}
		else if(arr[left] + arr[right] > target){
			right--;
		}
		else{
			left++;
		}

	}
	return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> price(n);
        for(int i=0;i<n;i++)
                cin>>price[i];
            int m;
            cin>>m;

             vector<long long> ans   = pairs(price,n,m);
            cout<<"Deepak should buy roses whose prices are "<<ans[0]<<" and "<<ans[1]<<"."<<endl;;
    }
    return 0;
}
