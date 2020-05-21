#include<iostream>
using namespace std;
bool isPalindrome(int* array, int first, int last){
	if(first >= last){
		return true;
	}
	if(array[first] == array[last] && isPalindrome(array, first + 1, last - 1)){
		return true;
	}
	return false;
}
int main(){
	int numOfElements;
	cin >> numOfElements;
	int array[100];
	for(int i = 0; i < numOfElements; i++){
		cin >> array[i];
	}
	isPalindrome(array, 0, numOfElements - 1) ? cout << "true" : cout << "false";
	return 0;
}
