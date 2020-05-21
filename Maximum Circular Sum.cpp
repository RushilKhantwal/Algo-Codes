
#include<iostream>
using namespace std;
int kadanesAlgo(int *array, int numOfElements){
	int i, currentSum = 0, maxSum = 0;
	for(i = 0; i < numOfElements; i++){
		currentSum += array[i];
		if(currentSum < 0){
			currentSum = 0;
		}
		if(currentSum > maxSum){
			maxSum = currentSum;
		}
	}
	return maxSum;
}
int max_sum_circular(int* Array, int numOfElements){
	int non_circular_sum, circular_sum;
	non_circular_sum = kadanesAlgo(Array, numOfElements);
	int totalSum = 0;
	for(int i = 0; i < numOfElements; i++){
		totalSum += Array[i];
		//flip the signs
		Array[i] = -Array[i];
	}
	circular_sum = totalSum + kadanesAlgo(Array, numOfElements);
	return max(circular_sum, non_circular_sum);
}
int main(){
	int testCases;
	cin >> testCases;
	while(testCases--){
		int numOfElements;
		cin >> numOfElements;
		int arr[1000];
		for(int i = 0; i < numOfElements; i++){
			cin >> arr[i];
		}
		cout << max_sum_circular(arr, numOfElements) << endl;
	}
	return 0;
}
