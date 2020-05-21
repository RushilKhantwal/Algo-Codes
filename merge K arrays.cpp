#include<bits/stdc++.h>
using namespace std;

int main()
{
        int k,n;
        cin>>k>>n;
        vector <int> ans(k*n);
            for(int i=0;i<k*n;i++)
            {
                cin>>ans[i];
            }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
                cout<<ans[i]<<" ";



}
