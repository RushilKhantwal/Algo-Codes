#include <bits/stdc++.h>

using namespace std;
void space(int k)
{
    for(int i=0;i<k;i++)
        cout<<" ";
}
void printPascal(int n)
{
    int k = n;
    for (int line = 1; line <= n; line++)
        {
                int C = 1;
                space(k--);
                for (int i = 1; i <= line; i++)
                    {
                                    cout<< C<<" ";
                                    C = C * (line - i) / i;
                     }

    cout<<"\n";
}
}


int main()
{
    int n;
    cin>>n;
    printPascal(n);
    return 0;
}
