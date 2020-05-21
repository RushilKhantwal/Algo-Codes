
#include<iostream>
#include<string.h>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

// Recursive function to convert
// string to integer
int stringToInt(string str)
{
    if (str.length() == 1)
        return (str[0] - '0');



    double y = stringToInt(str.substr(1));


    double x = str[0] - '0';

    x = x * pow(10, str.length() - 1) + y;
    return int(x);
}
using namespace std;
int main() {
	string s;
	cin>>s;
		cout<<stringToInt(s);
	return 0;
}
