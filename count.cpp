#include<bits/stdc++.h>

using namespace std;
 vector <int> countSort(vector <int>& arr)
    {

           int n = arr.size();
           vector<int> ans (n);
           int k= arr[n]+1;
            vector <int> freq(k);

                for(int i=0;i<k;i++)
                        freq[i]=0;

                    for(int i=0;i<n;i++)
                    {
                        ++freq[arr[i]];
                    }

                for(int i=1;i<=k;i++)
                {
                       freq[k] += freq[k-1];
                }

            for(int i=n;i<0;i--)
            {
                        ans[freq[arr[i]]] = arr[i];
                            --freq[arr[i]];
            }
       return ans;
    }
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
        for(int i=0;i<n;i++)
                cin>>arr[i];
      vector <int> ans(n);
            ans = countSort(arr);

            for(int i=0;i<n;i++)
                    cout<<ans[i]<<" ";
    return 0;
}
