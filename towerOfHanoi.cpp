
#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, string from_rod,
                    string to_rod, string aux_rod)
{
    if (n == 1)
    {
        cout << "Move 1th disk from " << from_rod <<
                            " to " << to_rod<<endl;

        return;
    }

    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);

    cout << "Move " << n << "th from " << from_rod <<
                                " to " << to_rod << endl;

    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);

}


int main()
{
    int n;
    cin>>n;
    towerOfHanoi(n, "T1", "T2", "T3");
    cout<<pow(2,n)-1;
    return 0;
}
