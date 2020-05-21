
#include<iostream>
using namespace std;
int main(){
	long long int N, a, h;
	cin >> N;
	if(N % 2 == 0){
		a = ((N * N) / 4) - 1;
		h = ((N * N) / 4) + 1;
	}
	else{
		a = ((N * N) - 1) / 2;
		h = ((N * N) + 1) / 2;
	}
	if(h * h == (a * a) + (N * N) && (N + a) > h && (a + h) > N && (N + h) > a)
		cout << a << " " << h;
	else
		cout << "-1";
}
