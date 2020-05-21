

#include<iostream>
using namespace std;

int main(){
	char Operator = '+';
	int num1, num2;
	while(Operator != 'x' || Operator != 'X'){
		cin >> Operator;
		if(Operator == '+' || Operator == '-' || Operator == '*' || Operator == '/' || Operator == '%'){
			cin >> num1 >> num2;
			switch(Operator){
				case '+': cout << num1 + num2 << endl;
						break;
				case '-': cout << num1 - num2 << endl;
						break;
				case '*': cout << num1 * num2 << endl;
						break;
				case '/': cout << num1 / num2 << endl;
						break;
				case '%': cout << num1 % num2 << endl;
						break;
			}
		}
		else if(Operator == 'x' || Operator == 'X')
			break;
		else
			cout << "Invalid operation. Try again.\n";
	}
	return 0;
}
