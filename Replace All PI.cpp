#include<iostream>
using namespace std;
void replaceAllPi(char *str, char *output_str, int i = 0, int j = 0){
	if(str[i] == '\0'){
		output_str[j] = '\0';
		cout << output_str << endl;
		return;
	}
	if(str[i] == 'p' && str[i + 1] == 'i'){
		output_str[j] = '3';
		output_str[j+1] = '.';
		output_str[j+2] = '1';
		output_str[j+3] = '4';
		replaceAllPi(str, output_str, i + 2, j + 4);
	}
	else{
		output_str[j] = str[i];
		replaceAllPi(str, output_str, i + 1, j + 1);
	}
}
int main(){
	int numOfLines;
	cin >> numOfLines;
	char strings[1000][1000], output_string[1000];
	for(int i = 0; i < numOfLines; i++){
		cin >> strings[i];
		replaceAllPi(strings[i], output_string);
	}
	return 0;
}
