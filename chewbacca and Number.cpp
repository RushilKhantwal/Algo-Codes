
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	long long int original, inverted = 0;
	int _10power = 0;
	cin >> original;
	while(original){
		if(original % 10 > 4){
			original += 9 - 2 * (original % 10);
		}
		inverted += (original % 10) * pow(10, _10power++);
		original /= 10;
	}
	long long int temp = inverted;
	int lastDigit = temp / pow(10, --_10power);
	if(lastDigit % 10 == 0)
		inverted += 9 * pow(10, _10power);
	cout << inverted;
	return 0;
}
