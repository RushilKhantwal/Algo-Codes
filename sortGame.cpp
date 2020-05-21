#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool myCompare(pair<string, int> p1, pair<string, int> p2){
	if(p1.second != p2.second){
		return p1.second > p2.second;
	}
	return p1.first < p2.first;
}
int main(){
	int min_salary;
	cin >> min_salary;
	int numOfEmp;
	cin >> numOfEmp;
	pair<string, int> employee[100005];
	for(int i = 0; i < numOfEmp; i++){
		cin >> employee[i].first >> employee[i].second;
	}
	sort(employee, employee + numOfEmp, myCompare);
	for(int i = 0; i < numOfEmp; i++){
		if(employee[i].second >= min_salary){
			cout << employee[i].first << " ";
			cout << employee[i].second << endl;
		}
	}
	return 0;
}
