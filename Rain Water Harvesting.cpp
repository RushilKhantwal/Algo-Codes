 #include<bits/stdc++.h>
using namespace std;

int findWater(int arr[], int n)
{
    // left[i] contains height of tallest bar to the
    // left of i'th bar including itself
    int left[n];

    // Right [i] contains height of tallest bar to
    // the right of ith bar including itself
    int right[n];

    // Initialize result
    int water = 0;

    // Fill left array
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
       left[i] = max(left[i-1], arr[i]);

    // Fill right array
    right[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--)
       right[i] = max(right[i+1], arr[i]);

    // Calculate the accumulated water element by element
    // consider the amount of water on i'th bar, the
    // amount of water accumulated on this particular
    // bar will be equal to min(left[i], right[i]) - arr[i] .
    for (int i = 0; i < n; i++)
       water += min(left[i],right[i]) - arr[i];

    return water;
}
int main() {

    int n, ans=0,left=0,right=0,j;

    cin>>n;
    int  arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<findWater(arr,n);
    // for(int i=0; i<n; i++){


    //      for( j=n-1; j>=0; j--){

    //          if(arr[i]>left){
    //              left=arr[i];
    //          }

    //          if(arr[j]>right){
    //              right=arr[j];
    //          }
    //      }
    //  if(left>right){
    //      ans = ans+left-arr[i];
    //      cout<<"1:"<<ans<<" ";
    //  }
    //  else{
    //  ans = ans +right-arr[i];
    //  cout<<"2:"<<ans<<" ";
    //  }
    // }
    // cout<<ans;
    return 0;

}
