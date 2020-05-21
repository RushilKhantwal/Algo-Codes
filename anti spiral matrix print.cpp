#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int n,m;
    cin>>m>>n;
    int a[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];

    int i, k = 0, l = 0;
stack<int>stk;
    /* k - starting row index
        m - ending row index
        l - starting column index
        n - ending column index
        i - iterator
    */

    while (k < m && l < n) {
        /* Print the first row from
               the remaining rows */
        for (i = l; i < n; ++i) {
             stk.push(a[k][i]);
        }
        k++;

        /* Print the last column
         from the remaining columns */
        for (i = k; i < m; ++i) {
            stk.push(a[i][n - 1]);
                    }
        n--;

        /* Print the last row from
                the remaining rows */
        if (k < m) {
            for (i = n - 1; i >= l; --i) {
                stk.push(a[m - 1][i] );
            }
            m--;
        }

        /* Print the first column from
                   the remaining columns */
        if (l < n) {
            for (i = m - 1; i >= k; --i) {
                stk.push(a[i][l]);
            }
            l++;
        }

    }
    while(!stk.empty())
    {
        int x = stk.top();
        cout<<x<<", ";
        stk.pop();
    }
    cout<<"END";
    return 0;
}
