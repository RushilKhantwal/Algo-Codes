#include<iostream>
using namespace std;
int main(){
	int numOfElements;
	cin >> numOfElements;
	int inputArray[1000005];
	int max_val = 0;
	for(int i = 0; i < numOfElements; i++){
		cin >> inputArray[i];
		max_val = max(max_val, inputArray[i]);
	}
	int frequencyArray[1000005] = {0};
	for(int i = 0; i < numOfElements; i++){
		int value = inputArray[i];
		frequencyArray[value]++;
	}
	//cout << max_val;//
	for(int i = 0; i <= max_val; i++){
		for(int j = 0; j < frequencyArray[i]; j++){
			cout << i << " ";
		}
	}
	return 0;
}
