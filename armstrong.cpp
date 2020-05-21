#include<bits/stdc++.h>
using namespace std;
bool isArm(int n)
{
    int sum = 0;
    int num = n;
    string str = to_string(n);
    int i = str.length();

        while( num !=0 )
        {
            sum += pow(num%10,i);
                num = num/10;
        }
    if (sum == n)
                return true;
  return false;
}
int main()
{
        int n,m;
        cin>>n>>m;
        for(int i=n;i<=m;i++)
                if(isArm(i))
                    cout<<i<<endl;
    return 0;
}
