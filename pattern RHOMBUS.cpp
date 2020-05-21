#include<iostream>
using namespace std;
void spaces (int n)
{
    for(int i=0;i<n;i++)
            cout<<" ";
}
int main()
{
    int n,count = 0, count1 = 0, k = 0;
    cin>>n;

    for(int i = 1; i <= n; ++i)
    {
        for(int space = 1; space <= n-i; ++space)
        {
            cout << "  ";
            ++count;
        }

        while(k != 2*i-1)
        {
            if (count <= n-1)
            {
                cout << i+k << " ";
                ++count;
            }
            else
            {
                ++count1;
                cout << i+k-2*count1 << " ";
            }
            ++k;
        }
        count1 = count = k = 0;

        cout << endl;
    }

    //last component
    spaces(n);
    cout<<" 1"<<endl;



    return 0;
}
