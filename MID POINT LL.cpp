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

  int length()
  {
      if(head == NULL)
            return 0;
       else
       {
      int count=0;

       node* itr = head;
       while(itr->next != NULL)
       {
           ++count;
           itr=itr->next;
       }
        return count+1;
    }

  }
  void mid ()
    {
        int m  = ceil(length()/2);
        node* itr = head;
        for(int i=0;i<m;i++)
            itr=itr->next;

        cout<<itr->x;
    }
};

int main()
{
    Linked L;
    int n;
    int x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        L.add2tail(x);
    }
    int len = L.length();
    cout<<len<<endl;
    L.mid();
    return 0;
}
