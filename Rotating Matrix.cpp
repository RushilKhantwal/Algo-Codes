#include<bits/stdc++.h>
using namespace std;

void rotateMatrix(int  mat[][10],int N)
{
    // Consider all squares one by one
    for (int x = 0; x < N / 2; x++) {
        // Consider elements in group of 4 in
        // current square
        for (int y = x; y < N - x - 1; y++) {
            // store current cell in temp variable
            int temp = mat[x][y];

            // move values from right to top
            mat[x][y] = mat[y][N - 1 - x];

            // move values from bottom to right
            mat[y][N - 1 - x] = mat[N - 1 - x][N - 1 - y];

            // move values from left to bottom
            mat[N - 1 - x][N - 1 - y] = mat[N - 1 - y][x];

            // assign temp to left
            mat[N - 1 - y][x] = temp;
        }
    }
}
int main()
{
int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
                cin>>a[i][j];
      int b[n][n];
                            for(int i=0;i<n;i++)
                                        for(int j=0;j<n;j++)
                                                b[i][j]+=a[i][j];
            rotateMatrix(a,n);
                          for(int i=0;i<n;i++)
                                        for(int j=0;j<n;j++)
                                                b[i][j]+=a[i][j];
        rotateMatrix(a,n);
                           for(int i=0;i<n;i++)
                                        for(int j=0;j<n;j++)
                                                b[i][j]+=a[i][j];
        rotateMatrix(a,n);
                            for(int i=0;i<n;i++)
                                        for(int j=0;j<n;j++)
                                                b[i][j]+=a[i][j];

        for(int i=0;i<n;i++)
        {   for(int j=0;j<n;j++)
                    cout<<b[i][j]<<" ";
               cout<<endl;
        }

    return 0;
}
