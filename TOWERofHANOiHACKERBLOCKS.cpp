#include<iostream>
using namespace std;
void towerOfHanoi(int n, char source, char helper, char target){
	if(n == 0){
		return;
	}
	towerOfHanoi(n-1, source, target, helper);
	cout << "Moving ring " << n << " from " << source << " to " << target << endl;
	towerOfHanoi(n-1, helper, source, target);
}
int main(){
	int numOfDiscs;
	cin >> numOfDiscs;
	towerOfHanoi(numOfDiscs, 'A', 'C', 'B');
	return 0;
}
