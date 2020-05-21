#include<iostream>
using namespace std;
void spiral_print(int a[][1000],int m, int n)
{
	int startRow=0;
	int startCol = 0;
	int endRow=m-1;
	int endCol=n-1;
	while(startRow<=endRow and startCol<=endCol)
		{
			for(int i=startRow;i<=endRow;i++)
				{
					cout<<a[i][startCol]<<", ";
				}
				startCol++;
			for(int i=startCol;i<=endCol;i++)
				{
					cout<<a[endRow][i]<<", ";
				}
				endRow--;
			if(endRow>startRow)
			{
				for(int i=endRow;i>=startRow;i--)
					cout<<a[i][endCol]<<", ";
				endCol--;
			}

			if(endCol>startCol)
			{
				for(int i=endCol;i>=startCol;i--)
					cout<<a[startRow][i]<<", ";
				startRow++;
			}

		}
	cout<<"END";

}
int main()
{
	int a[1000][1000];
	int n,m;
	cin>>m>>n;
	for(int i=0;i<m;i++)
		for(int j =0;j<n;j++)
			cin>>a[i][j];
	spiral_print(a,m,n);
	return 0;
}
