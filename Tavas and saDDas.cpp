#include<string>
#include<iostream>
using namespace std;
int main(){
	string num;
	cin >> num;
	int index = 0;
	index = (1 << num.length()) - 2; // no of len-1 digits numbers
	for(int i = num.length() - 1; i >= 0; i--){
		if(num[i] == '7'){
			index += (1 << (num.length() - 1 - i));
		}
	}
	cout << index + 1;
	return 0;
}
