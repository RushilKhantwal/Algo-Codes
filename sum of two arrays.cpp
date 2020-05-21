#include<iostream>
using namespace std;
int main(){
	int len1;
	cin >> len1;
	int arr1[1005] = {0};
	for(int i = len1 - 1; i >= 0; i--){
		cin >> arr1[i];
	}
	int len2;
	cin >> len2;
	int arr2[1005] = {0};
	for(int i = len2 - 1; i >= 0; i--){
		cin >> arr2[i];
	}
	int ans[1005] = {0}, carry = 0, ans_size = 0;
	for(int i = 0; i < len1 || i < len2; i++){
		ans[i] = (carry + arr1[i] + arr2[i]) % 10;
		carry = (arr1[i] + arr2[i]) / 10;
		ans_size++;
	}
	while(carry){
		ans[ans_size] = carry % 10;
		carry /= 10;
		ans_size++;
	}
	for(int i = ans_size - 1; i >= 0; i--){
		cout << ans[i] << ", ";
	}
	cout << "END";
	return 0;
}
