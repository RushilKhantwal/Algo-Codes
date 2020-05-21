/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<bits/stdc++.h>

using namespace std;

void C(string str[],int n)
{
    vector<int> COUNT;


        for(int i=0;i<n;i++)
            {
                    int c=0;
                    char* v  = str[i];
                        for(int j=0;j<i;j++)
                            {
                                char* f = str[j];
                                int res = strcmp(f,v);

                                if(res < 0)
                                    ++c;
                            }
                     COUNT.push_back(c);
            }

        for(int i=0;i<COUNT.size();i++)
            cout<<COUNT[i]<<endl;

}

int main()
{

    int n;
    cin>>n;
    string str[n];
    for(int i=0;i<n;i++)
        {
            cin>>str[i];
        }


    C(str,n);
}
