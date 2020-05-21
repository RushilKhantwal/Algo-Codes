#include<iostream>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int c1, c2, c3, c4;
		int n, m;
		int a[1001], b[1001];
		int rickCost = 0, cabCost = 0;
		int i;

		cin >> c1 >> c2 >> c3 >> c4;
		cin >> n >> m;
		for(i = 0; i < n; i++)
			cin >> a[i];
		for(i = 0; i < m; i++)
			cin >> b[i];

		for(i = 0; i < n; i++){
			rickCost += min(a[i] * c1, c2);
		}
		for(i = 0; i < m; i++){
			cabCost += min(b[i] * c1, c2);
		}
		int finalAns = min(c4, min(cabCost, c3) + min(rickCost, c3));
		cout << finalAns << endl;
	}
	return 0;
}
