#include<iostream>
#include<stack>
using namespace std;
void printStockSpan(int* stock, int numOfStocks, int* stockSpan){
	stack<int> prevHighestVal;
	for(int i = 0; i < numOfStocks; i++){
		while(!prevHighestVal.empty() && stock[prevHighestVal.top()] < stock[i]){
			prevHighestVal.pop();
		}
		stockSpan[i] = prevHighestVal.empty() ? i + 1 : (i - prevHighestVal.top());
		prevHighestVal.push(i);
	}
	for(int i = 0; i < numOfStocks; i++){
		cout << stockSpan[i] << " ";
	}
	cout << "END";
}
void stockSpanAlt(int* arr, int numOfStocks){
	stack<int> s;
	int ans[100];
	for(int day = 0; day < numOfStocks; ++day){
		int curPrice = arr[day];
		while(s.empty() == false && arr[s.top()] < curPrice){
			s.pop();
		}
		int betterDay = s.empty() ? 0 : s.top();
		int span = day - betterDay;
		ans[day] = span;
		s.push(day);
	}
	for(int i = 0; i < numOfStocks; i++){
		cout << ans[i] << " ";
	}
}
int main(){
	int numOfStocks;
	cin >> numOfStocks;
	int stock[100];
	for(int i = 0; i < numOfStocks; i++){
		cin >> stock[i];
	}
	int stockSpan[100];
	printStockSpan(stock, numOfStocks, stockSpan);
	//stockSpanAlt(stock, numOfStocks);
	return 0;
}
