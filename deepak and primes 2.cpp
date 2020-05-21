#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool sieve[1000001]={0};
    for(int i=2;i*i<=1000000;i++)
        if(!sieve[i])
            for(int j=i*i;j<=1000000;j+=i)
                sieve[j]=1;

          sieve[1]=sieve[0]=0;

    vector<int> prime;
    for(int i=2;i<=1000000;i++)
        if(!sieve[i])
            prime.push_back(i);

    int T;
    cin>>T;
    while(T--)
    {
        long long a,b;
        cin>>a>>b;
        bool mark[100001]={0};
        for(int i=0;i<prime.size();i++)
        {
            long long num=prime[i];
            long long first=ceil(a/double(num))*num;
            for(long long j=first;j<=b;j+=prime[i])
                if(j!=prime[i])
                    mark[j-a]=1;
        }
        for(long long j=a;j<=b;j++)
            if(!mark[j-a])
                cout<<j<<endl;
        if(T!=0)
            cout<<endl;

    }
}
