#include<bits/stdc++.h>

using namespace std;

int Search(int matrix[][30],int n,int m,int ele)
{
            for(int i=0;i<n;i++)
                    for(int j=0;j<m;j++)
                            if(matrix[i][j] == ele)
                                    return 1;

    return 0;
}
int main()
{
    int m,n;
    cin>>n>>m;
    int matrix[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
                cin>>matrix[i][j];
    int element;
    cin>>element;
    cout<<Search(matrix,n,m,element);

    return 0;
}
