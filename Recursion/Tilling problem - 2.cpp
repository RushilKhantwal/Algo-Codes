#include <iostream>
using namespace std;
int numOfWays(int n, int m){
	if(n <= 0){
		return 0;
	}
	if(n == 1){
		return 1;
	}
	if(n == m){
		return 2;
	}
	return numOfWays(n-1, m) + numOfWays(n-m, m);
}
int main(){
	int testCases;
	cin >> testCases;
	while(testCases--){
		int n, m;
		cin >> n >> m;
		cout << numOfWays(n, m) %  1000000007 << endl;
	}
}
