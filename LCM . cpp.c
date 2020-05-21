#include<iostream>
using namespace std;
long long int gcd(long long int a, long long int b){
	if(b == 0){
		return a;
	}
	return gcd(b, a%b);
}
int main(){
	long long int num1, num2;
	cin >> num1 >> num2;
	cout << (num1 * num2) / gcd(num1, num2);
	return 0;
}
