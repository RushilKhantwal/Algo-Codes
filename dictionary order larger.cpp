#include<iostream>
#include<string>
using namespace std;
void printAllPermutations(string original, string str, string outputStr = ""){
	if(str.length() <= 0){
		if(outputStr > original && outputStr != original){
			outputStr.push_back('\0');
			cout << outputStr << endl;
		}
		return;
	}
	for(int i = 0; str[i] != '\0'; i++){
		outputStr.push_back(str[i]);
		string remaining = str;
		remaining.erase(remaining.begin() + i);
		printAllPermutations(original, remaining, outputStr);
		outputStr.pop_back();
	}
}
int main(){
	string str;
	cin >> str;
	printAllPermutations(str, str);
	return 0;
}
