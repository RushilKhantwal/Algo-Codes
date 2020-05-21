#include<iostream>
using namespace std;
int bitonic(int arr[], int n)
{
    // Length of increasing subarray
    // ending at all indexes
    int inc[n];

    // Length of decreasing subarray
    // starting at all indexes
    int dec[n];
    int i, max;

    // length of increasing sequence
    // ending at first index is 1
    inc[0] = 1;

    // length of increasing sequence
    // starting at first index is 1
    dec[n-1] = 1;

    // Step 1) Construct increasing sequence array
    for (i = 1; i < n; i++)
    inc[i] = (arr[i] >= arr[i-1])? inc[i-1] + 1: 1;

    // Step 2) Construct decreasing sequence array
    for (i = n-2; i >= 0; i--)
    dec[i] = (arr[i] >= arr[i+1])? dec[i+1] + 1: 1;

    // Step 3) Find the length of
    // maximum length bitonic sequence
    max = inc[0] + dec[0] - 1;
    for (i = 1; i < n; i++)
        if (inc[i] + dec[i] - 1 > max)
            max = inc[i] + dec[i] - 1;

    return max;
}
int Bitonic(int *A, int n)
{
    // if A is empty
    if (n == 0)
        return 0;

    // initializing max_len
    int maxLen=1;

    int start=0;
    int nextStart=0;

    int j =0;
    while (j < n-1)
    {
        // look for end of ascent
        while (j<n-1 && A[j]<=A[j+1])
            j++;

        // look for end of descent
        while (j<n-1 && A[j]>=A[j+1]){

            // adjusting nextStart;
            // this will be necessarily executed at least once,
            // when we detect the start of the descent
            if (j<n-1 && A[j]>A[j+1])
                nextStart=j+1;

            j++;
        }

        // updating maxLen, if required
        maxLen = max(maxLen,j-(start-1));

        start=nextStart;
    }

    return maxLen;
}
int main() {
	int q;
	cin>>q;
	while(q--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i =0;i<n;i++)
			cin>>arr[i];
		cout<<bitonic(arr,n)<<endl;
	}
	return 0;
}
