#include<iostream>
#include<string>
using namespace std;
int main(){
	int testCase;
	cin >> testCase;
	for(int i = 0; i < testCase; i++){
		string s1, s2, ans;
		cin >> s1;
		cin >> s2;
		for(int j = 0; s1[j] != '\0'; j++){
			if(s1[j] == s2[j])
				ans.append("0");
			else
				ans.append("1");
		}
		cout << ans << endl;
	}
	return 0;
}
