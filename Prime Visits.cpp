#include<iostream>
using namespace std;
int main(){
	int testCases;
	cin >> testCases;
	while(testCases--){
		long int a, b;
		cin >> a >> b;
		int prime[1000000] = {0};
        prime[0] = prime[1] = 1;
		for(int i = 2; i*i <= b; i++){
			if(prime[i] == 0){
				for(int j = i*i; j <= b; j += i){
					prime[j] = 1;
				}
			}
		}
		int count = 0;
		for(int i = a; i <=b; i++){
			if(prime[i] == 0){
                //cout << i << " ";
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}
