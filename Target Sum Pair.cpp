
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int arr[1000], target, numOfElements;
	cin >> numOfElements;
	for(int i = 0; i < numOfElements; i++){
		cin >> arr[i];
	}
	cin >> target;
	sort(arr, arr + numOfElements);
	int left = 0, right = numOfElements - 1;
	while(left < right){
		if(arr[left] + arr[right] == target){
			cout << arr[left] << " and " << arr[right] << endl;
			left++;
			right--;
		}
		else if(arr[left] + arr[right] > target){
			right--;
		}
		else{
			left++;
		}

	}
	return 0;
}
