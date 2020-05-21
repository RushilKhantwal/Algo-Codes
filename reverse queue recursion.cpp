#include<bits/stdc++.h>
using namespace std;

void printQueue(queue<long long int> Queue)
{
    while (!Queue.empty()) {
        cout << Queue.front() << ", ";
        Queue.pop();
    }
    cout<<"END";
}

// Recursive function to reverse the queue
void reverseQueue(queue<long long int>& q)
{
    // Base case
    if (q.empty())
        return;

    // Dequeue current item (from front)
    long long int data = q.front();
    q.pop();

    // Reverse remaining queue
    reverseQueue(q);

    // Enqueue current item (to rear)
    q.push(data);
}
int main()
{
    int n;
    cin>>n;
    queue <long long int> Q;
        long long int x;
        for(int i=0;i<n;i++)
            {
                cin>>x;
                Q.push(x);
            }
            reverseQueue(Q);
            printQueue(Q);
    return 0;
}
