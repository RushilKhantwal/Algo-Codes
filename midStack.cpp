#include <bits/stdc++.h>
using namespace std;


class DLLNode
{
    public:
    DLLNode *prev;
    int data;
    DLLNode *next;
};

class myStack
{
    public:
    DLLNode *head;
    DLLNode *mid;
    int count;
};


myStack *createMyStack()
{
    myStack *ms = new myStack();
    ms->count = 0;
    return ms;
};


void push(myStack *ms, int new_data)
{

    DLLNode* new_DLLNode = new DLLNode();
    new_DLLNode->data = new_data;


    new_DLLNode->prev = NULL;


    new_DLLNode->next = ms->head;


    ms->count += 1;


    if (ms->count == 1)
    {
        ms->mid = new_DLLNode;
    }
    else
    {
        ms->head->prev = new_DLLNode;

        if(!(ms->count & 1))
        ms->mid = ms->mid->prev;
    }


    ms->head = new_DLLNode;
}


int pop(myStack *ms)
{

    if (ms->count == 0)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    DLLNode *head = ms->head;
    int item = head->data;
    ms->head = head->next;

    if (ms->head != NULL)
        ms->head->prev = NULL;

    ms->count -= 1;

    if ((ms->count) & 1 )
        ms->mid = ms->mid->next;

    free(head);

    return item;
}

int findMiddle(myStack *ms)
{
    if (ms->count == 0)
    {
        cout << "Stack is empty now\n";
        return -1;
    }

    return ms->mid->data;
}


int main()
{

    myStack *ms = createMyStack();
    int n;
    cin>>n;
    int x;
    for(int i=0;i<n;i++)
    {
                cin>>x;
                push(ms, x);
    }


    cout << findMiddle(ms) << endl;
    return 0;
}
