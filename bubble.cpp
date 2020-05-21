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

void bsort(int n)
{
    node* temp = new node();
    node* p = new node();
    node* tem = new node();
    int t;
    for(int i=0;i<n-1;i++)
    {
         temp = head;
         tem = head;
         p = head;

        for(int j=0;j<i;j++)
        {
            p= p->next;
            tem = tem->next;
            temp= temp->next;
        }
        while(temp->next != NULL)
        {
            if(tem->data > temp->data)
            {
                tem = temp;
            }
            temp = temp->next;

        }
      if(tem->data >temp->data)
            tem = temp;

       t = tem->data;
       tem->data = p->data;
       p->data = t;

    }
}

};

int main()
{
        LinkedList L;

        int  n,n1;
       int t;
       cin>>t;
    while(t--)
    {
        cin>>n;
        int x;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            L.add2head(x);
        }
            cin>>n1;
        for(int i=0;i<n1;i++)
       {
          cin>>x;
           L.add2head(x);
       }
        L.bsort(n+n1);
        L.display();

    }

    return 0;
}
