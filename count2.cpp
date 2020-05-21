#include<bits/stdc++.h>
using namespace std;

void countSort(vector <int>& arr)
{
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    vector<int> count(range), output(arr.size());
    for(int i = 0; i < arr.size(); i++)
        count[arr[i]-min]++;

    for(int i = 1; i < count.size(); i++)
           count[i] += count[i-1];

    for(int i = arr.size()-1; i >= 0; i--)
    {
         output[ count[arr[i]-min] -1 ] = arr[i];
              count[arr[i]-min]--;
    }

    for(int i=0; i < arr.size(); i++)
            arr[i] = output[i];
}

void printArray(vector <int> & arr)
{
    for (int i=0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int a[n];

    int x,y;
    cin>>x>>y;
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<int> arr(n);
    for(int i=0;i<n;i++)
            arr[i]=a[i];

    countSort (arr);
    printArray (arr);
 }
    return 0;
}
