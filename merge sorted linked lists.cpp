#include<bits/stdc++.h>
using namespace std;
struct node{
    int x;
    node* next;
};
class Linked{
    node*head;
    node*tail;
public:
    Linked()
    {
        head = tail = NULL;

    }
   void add2tail(int x)
   {
       node* t = new node();
       t->x=x;
       if(head == NULL)
       {
           head = tail = t;
       }
       else
       {
           tail->next = t;
            tail = t;
   /*        node* itr = new node();
           itr= head;
           while(itr ->next != NULL)
           {
               itr = itr->next;
           }
           itr->next = t;
           tail = t; */
       }
   }
   void display()
   {
       if(head == NULL)
            return;
       else
       {
              node* itr = new node();
           itr= head;
           while(itr ->next != NULL)
           {
               cout<<itr->x<<" ";
               itr = itr->next;
           }
           cout<<itr->x;

       }
   }
 void Merge(Linked L1,Linked L2)
  {
      Linked L3;

        node* p = L1.head;
        node* q = L2.head;
    while( p->next != NULL && q->next != NULL)
        if(p->x <= q->x)
        {
            L3.add2tail(p->x);
            p=p->next;
        }
        else
        {
            L3.add2tail(q->x);
            q=q->next;
        }
        while( p->next != NULL)
        {
            L3.add2tail(p->x);
            p = p->next;
        }
        while(q->next != NULL)
        {

            L3.add2tail(q->x);
            q=q->next;
        }
         L3.display();
  }
};struct node{
    int x;
    node* next;
};
class Linked{
    node*head;
    node*tail;
public:
    Linked()
    {
        head = tail = NULL;

    }
   void add2tail(int x)
   {
       node* t = new node();
       t->x=x;
       if(head == NULL)
       {
           head = tail = t;
       }
       else
       {
           tail->next = t;
            tail = t;
   /*        node* itr = new node();
           itr= head;
           while(itr ->next != NULL)
           {
               itr = itr->next;
           }
           itr->next = t;
           tail = t; */
       }
   }
   void display()
   {
       if(head == NULL)
            return;
       else
       {
              node* itr = new node();
           itr= head;
           while(itr ->next != NULL)
           {
               cout<<itr->x<<" ";
               itr = itr->next;
           }
           cout<<itr->x;

       }
   }
 void Merge(Linked L1,Linked L2)
  {
      Linked L3;

        node* p = L1.head;
        node* q = L2.head;
    while( p->next != NULL && q->next != NULL)
        if(p->x <= q->x)
        {
            L3.add2tail(p->x);
            p=p->next;
        }
        else
        {
            L3.add2tail(q->x);
            q=q->next;
        }
        while( p->next != NULL)
        {
            L3.add2tail(p->x);
            p = p->next;
        }
        while(q->next != NULL)
        {

            L3.add2tail(q->x);
            q=q->next;
        }
         L3.display();
  }
};
int main()
{
    Linked L,M;
int t;
cin>>t;
int x;
while(t--)
{
  int n,m;
  cin>>n>>m;

  for(int i=0;i<n;i++)
        {
            cin>>x;
            L.add2tail(x);
        }
     for(int i=0;i<m;i++)
        {
            cin>>x;
            M.add2tail(x);
        }
            Linked res;
             res.Merge(L,M);
}


    return 0;
}
