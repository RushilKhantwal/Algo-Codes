
#include<iostream>
#include<cmath>
using namespace std;
long int greatestInt(long int num, int power){
	long int start = 1, end = num, mid, base = 1;
	while(start <= end){
		mid = (start + end) / 2;
		if(pow(mid, power) <= num){
			base = mid;
			start = mid + 1;
		}
		else{
			end = mid - 1;
		}
	}
	return base;
}
int main(){
	int testCases;
	cin >> testCases;
	while(testCases--){
		long int num;
		cin >> num;
		int power;
		cin >> power;
		cout << greatestInt(num, power) << endl;
	}
	return 0;
}
