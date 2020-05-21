#include<bits/stdc++.h>
using namespace std;
int highestPowerof2(int n)
{
    int res = 0;
    for (int i=n; i>=1; i--)
    {
        // If i is a power of 2
        if ((i & (i-1)) == 0)
        {
            res = i;
            break;
        }
    }
    return res;
}
int minSteps(int n)
{
       if (ceil(log2(n)) == floor(log2(n)))
                return 1;
       else{
             int steps = 0;

                      while( n > 2)
                        {
                             int near = highestPowerof2(n);
                            n = n - near;
                            ++steps;
                        }
                        if(n == 0)
                            return steps;

                return steps + n;
       }
}
int main()
{
        int t;
        cin>>t;

        while(t--)
        {
            int n;
            cin>>n;
            cout<<minSteps(n)<<endl;

        }

    return 0;
}
