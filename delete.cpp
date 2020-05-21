#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node* next;
};
struct node* swap(struct node* ptr1, struct node* ptr2)
{
    struct node* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}
class LinkedList
{
    node* head;
    node* tail;
public:
    LinkedList()
        {
           head = tail = NULL;
        }
   void  add2head(int x)
    {
        node* temp = new node();
        temp->data = x;
        if(head == NULL)
        {
                head = temp;
                tail = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }
    void add2tail(int x)
    {
        node* temp = new node();
        temp->data = x;

        if(head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            node* t= new node();

            t= head;
            while(t->next != NULL)
            {
                t = t->next;
            }
            t->next = temp;
            tail = temp;
        }
    }
    int Length()
{
    int count=0;
        if(head == NULL)
        {
            return -1;
        }
        else
        {
            node* Node = new node();
                Node = head;
                while( Node->next != NULL)
                {
                    ++count;
                    Node = Node->next;
                }
            ++count;
            return count;
        }
}
    void display()
    {
        if(head == NULL)
        {
            cout<<"\nList Empty!";
        }
        else
        {
            node* t = new node();
            t = head;
            while(t->next != NULL)
            {
                cout<<t->data<<" ";
                t=t->next;
            }
            cout<<t->data;

        }
    }
    void deleteAtStart()
{

    if(head == NULL)
    {
        cout<<" \n \n The list is Empty \n \n";
        return;
    }
    if(head->next == NULL)
    {
        node* Node = head;
        head = tail = NULL;
        delete Node;
        return;
    }

    else
    {
        node* Node = new node();

        Node = head;
        head = Node->next;
        delete Node;
    }
}
    void deleteAtEnd()
{
    if( tail == NULL)
    {
        cout<<"\n \n The list is empty \n \n ";
        return;
    }
    if(head->next == NULL)
    {
        node* Node = tail;
        tail = head = NULL;
        delete Node;
        return;
    }
    else
    {
        node* Node = new node();

        Node = tail;
        node* temp = new node();
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        tail = temp;
        tail->next = NULL;
        delete Node;
    }
}
  void deleteAt(int x)
  {
        if(x == 0)
    {
        deleteAtStart();
        return;
    }
    if(x == Length()-1)
    {
        deleteAtEnd();
        return;
    }
    if(x < 0)
    {
        cout<<"\n \n Wrong Index Input \n \n ";
    }
    else
    {
        if(x > Length()-1)
        {
            cout<<"\n \n Index exceeds the Length Bounds \n \n";
        }
        else
        {
            node* Node = new node();
            node* temp = new node();
            Node = head;
            for(int i=0 ; i < (x - 2); i++)
            {
                Node = Node->next;
            }
            temp = Node->next;
            Node->next = temp->next;
            delete temp;
        }
    }
  }
};

int main()
{
        LinkedList L;
        int  n;
        cin>>n;
        int q;
        cin>>q;
        int x;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            L.add2tail(x);
        }
     int index;
for(int i=0;i<q;i++)
{
        cin>>index;
        L.deleteAt(index);
        L.display();
}


    return 0;
}
