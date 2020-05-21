#include<iostream>
#include<string>
using namespace std;
void appendX2end(string &str, int index, int org_len){
	if(index == str.length()){
		str.append((org_len - str.length()), 'x');
		return;
	}
	if(str[index] == 'x'){
		str.erase(str.begin() + index);
		appendX2end(str, index, org_len);
	}
	else{
		appendX2end(str, index + 1, org_len);
	}
}
int main(){
	string str;
	cin >> str;
	appendX2end(str, 0, str.length());
	cout << str;
	return 0;
}
