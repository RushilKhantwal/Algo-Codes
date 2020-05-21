#include <iostream>
using namespace std;
int foundAtLast(long long int *a, int numOfElements, long long int key){
	int index = numOfElements - 1;
	if(index == -1){
		return -1;
	}
	if(a[index] == key){
		return index;
	}
	return foundAtLast(a, numOfElements - 1, key);
}
int main(){
	long long int array[1000];
	int numOfElements;
	cin >> numOfElements;
	for(int i = 0; i < numOfElements; i++){
		cin >> array[i];
	}
	long long int key;
	cin >> key;
	cout << foundAtLast(array, numOfElements, key);
}
