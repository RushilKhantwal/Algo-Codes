#include <bits/stdc++.h>
using namespace std;

int minIndex(queue<int> &q, int sortedIndex)
{
    int min_index = -1;
    int min_val = INT_MAX;
    int n = q.size();
    for (int i=0; i<n; i++)
    {
        int curr = q.front();
        q.pop();


        if (curr <= min_val && i <= sortedIndex)
        {
            min_index = i;
            min_val = curr;
        }
        q.push(curr);

    }
    return min_index;
}

void insertMinToRear(queue<int> &q, int min_index)
{
    int min_val;
    int n = q.size();
    for (int i = 0; i < n; i++)
    {
        int curr = q.front();
        q.pop();
        if (i != min_index)
            q.push(curr);
        else
            min_val = curr;
    }
    q.push(min_val);
}

void sortQueue(queue<int> &q)
{
    for (int i = 1; i <= q.size(); i++)
    {
        int min_index = minIndex(q, q.size() - i);
        insertMinToRear(q, min_index);
    }
}


int main()
{
  queue<int> q;
 int T;
 cin>>T;
 int n;
 int x;
 while(T>0)
 {
     cin>>n;
        for(int i=0;i<n;i++)
            {
                    cin>>x;
                    q.push(x);
            }

            sortQueue(q);

            while (q.empty() == false)
            {
                cout << q.front() << " ";
                    q.pop();
            }
            --T;
            cout << endl;
 }
  return 0;
}
