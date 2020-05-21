#include<bits/stdc++.h>

using namespace std;
struct node
{
    int data;
    node* next;
    node* prev;
};
class linkedlist
{
    node* head;
    node* tail;
public:
    linkedlist()
    {
        head=tail=NULL;
    }
    void add2tail(int x)
    {
        node* temp = new node();
        temp->data = x;
        if(head == NULL)
        {
            head = tail = temp;
        }
        else if(head-> next == NULL)
        {
            head->next= temp;
            temp->prev = head;
            tail = temp;
        }
        else
        {
            node* t = new node();
            t= head;
            while( t->next != NULL)
            {
                t= t->next;
            }
            t->next = temp;
            temp->prev = t;
            tail= temp;
        }
    }
  int kth(int x)
  {
      node* temp = new node();
      temp = tail;

        for(int i=0;i<x;i++)
        {
            temp=temp->prev;
        }
     return temp->data;
  }
};
int main()
{
    linkedlist L ;
    int n;
    do
    {
        cin>>n;
        L.add2tail(n);

    }while(n != -1);

    int k;
    cin>>k;

    int result = L.kth(k);
    cout<<result;
        return 0;
}
