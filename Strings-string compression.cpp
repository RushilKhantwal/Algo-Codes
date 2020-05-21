#include <string>
#include <iostream>
using namespace std;
int main() {
    std::string s, compressed, fstr;
    int i, freq = 0, flag = 1;;
    char currentChar;
    getline(cin, s);
    for(i = 0; i < s.size(); i++){
        if(flag == 1){
            currentChar = s[i];
            freq = 1;
            flag = 2;
        }
        else{
            if(s[i] == currentChar){
                freq++;
            }
            else{
                compressed.push_back(currentChar);
					if(freq >1)
					{	fstr = std::to_string(freq);
			    		compressed.append(fstr);
					}
                flag = 1;
                freq = 0;
                i--;
            }
        }
    }
    compressed.push_back(currentChar);
    if(freq >1)
					{	fstr = std::to_string(freq);
			    		compressed.append(fstr);
					}
    cout << compressed;
    return 0;
}
