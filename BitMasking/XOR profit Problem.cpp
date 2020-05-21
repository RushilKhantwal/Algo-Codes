#include<iostream>
using namespace std;
int main(){
	int x, y;
	cin >> x >> y;
	int maxXOR = 0;
	for(int i = x; i < y; i++){
		for(int j = i + 1; j <= y; j++){
			maxXOR = max((i^j),maxXOR);
		}
	}
	cout << maxXOR;
	return 0;
}
