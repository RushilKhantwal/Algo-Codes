#include<iostream>
using namespace std;

int main()
{
     int n,m;
    cin>>m>>n;
    int arr[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];

    int i, k = 0, l = 0;

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
            cout << a[i][k] << ", ";
        }
        k++;

        /* Print the last column
         from the remaining columns */
        for (i = k; i < m; ++i) {
            cout << a[n-1][i] << ", ";
        }
        n--;

        /* Print the last row from
                the remaining rows */
        if (k < m) {
            for (i = n - 1; i >= l; --i) {
                cout << a[i][m-1] << ", ";
            }
            m--;
        }

        /* Print the first column from
                   the remaining columns */
        if (l < n) {
            for (i = m - 1; i >= k; --i) {
                cout << a[1][i] << ", ";
            }
            l++;
        }

    }
    cout<<"END";
    return 0;
}
