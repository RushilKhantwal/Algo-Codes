#include<iostream>
#include<vector>
using namespace std;
string str(long long m)
{
        int odd=0;
        int even=0;
            while( m !=0 )
            {
                if( ((m%10)%2 )==0)
                        even+=m%10;
                else
                        odd+=m%10;

                m=m/10;
            }
        if( odd%3 == 0 || even %4 ==0)
                return "Yes\n";
    return "No\n";
}
int main()
{
    int n;
    cin>>n;

    vector <long long> arr(n);

        for(auto i = 0;i<n;i++)
                cin>>arr[i];
        for(auto i=0;i<n;i++)
               cout<<str(arr[i]);


    return 0;
}
