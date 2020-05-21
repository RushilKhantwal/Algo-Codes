int octalToDecimal(int n)
{
    int num = n;
    int dec_value = 0;

    // Initializing base value to 1, i.e 8^0
    int base = 1;

    int temp = num;
    while (temp) {

        // Extracting last digit
        int last_digit = temp % 10;
        temp = temp / 10;

        // Multiplying last digit with appropriate
        // base value and adding it to dec_value
        dec_value += last_digit * base;

        base = base * 8;
    }

    return dec_value;
}

#include<iostream>
using namespace std;
void decToOctal(long long int n)
{

    // array to store octal number
   long long int octalNum[100];

    // counter for octal number array
    int i = 0;
    while (n != 0) {

        // storing remainder in octal array
        octalNum[i] = n % 8;
        n = n / 8;
        i++;
    }

    // printing octal number array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << octalNum[j];
}

int main() {
	long long int n;
	cin>>n;
	decToOctal(n);
	return 0;
}
