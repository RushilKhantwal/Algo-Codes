#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int arr[1000], numOfElements, target;
	cin >> numOfElements;
	for(int i = 0; i < numOfElements; i++){
		cin >> arr[i];
	}
	cin >> target;
	sort(arr, arr + numOfElements);
	for(int i = 0; i < numOfElements; i++){
		int left = i + 1, right = numOfElements - 1;
		while(left < right){
			if(arr[i] + arr[left] + arr[right] == target){
				cout << arr[i] << ", " << arr[left] << " and " << arr[right] << endl;
				left++;
				right--;
			}
			else if(arr[i] + arr[left] + arr[right] > target)
				right--;
			else
				left++;
		}
	}
	return 0;
}
