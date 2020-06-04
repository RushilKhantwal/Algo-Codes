#include<bits/stdc++.h>
using namespace std;
#define ll long long int


//CLASS NODE WITH A INT DATA TYPE AND A SELF-REFRENTIAL POINTER
class node
{
public:
	int data;
	node* next;
	node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};
//CLASS OF TYPE LINKED LIST
class LinkedList {

};

//METHOD TO CALCULATE THE LENGTH OF THE LINKED LIST
int length(node* head)
{
	if(head == NULL)
		return 0;
	else
	{
		int len =0;
		while(head != NULL)
		{
			++len;
			head= head->next;
		}
		return len;
	}
}
//ADDING TO THE HEAD OF THE LIST
void add2head(node* &head, int data)
{
	node* n = new node(data);

	if (head == NULL)
		head = n;
	else
	{
		n->next = head;
		head = n;
	}

}

//ADDING TO THE END OF THE LIST
void add2tail(node*&head, int data)
{
	if (head == NULL)
	{
		head = new node(data);
		return;
	}

	node* tail = head;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = new node(data);
	return;

}

//ADDING TO A SPECIFIED INDEX IN THE LINKED LIST
void add2pos(node*&head,int data,int pos)
{
	if(head == NULL or pos == 0)
	{
		add2head(head,data);
		return;
	}

	if(pos > length(head))
	{
		add2tail(head,data);
		return;
	}

	else
	{
		node* itr = head;
		for(int i =1;i<pos-1;i++)
		{
			itr= itr->next;
		}
		node*t = new node(data);  
		t->next = itr->next;
		itr->next = t;
	}
}

//DELETING THE ELEMENT AT THE HEAD OF THE LIST

void delHead(node* &head)
{
	if(head == NULL)
	{
		return;
	}
	else
	{
		node* t = head;
		head = head->next;
		delete t;
	}
}

//DELETING THE ELEMENT AT THE END OF THE LIST

void delTail(node* & head)
{
	if(head == NULL)
	{
		return;

	}
	else
	{
		node* tail = head;
		while(tail -> next ->next != NULL)
		{
			tail = tail -> next;
		}
			node* t = tail -> next;
			tail -> next  = NULL;
			delete t;

	}
}
void reverse(node*&head)
{
	node* c = head;
	node* p = NULL;
	node* n;

	while (c != NULL)
	{
		n = c->next;
		c->next  = p;
		p = c;
		c = n;
	}
	head  = p;
}
//DELETING THE ELEMENT PLACED AT DESIRED POSITION IN THE LIST
void delPos(node* &head, int pos)
{
	if(head == NULL)
	{
		return;
	}
	else
	{
		if(pos < 0)
			{
				delHead(head);
				return;
			}
		if(pos>length(head))
			{
				delTail(head);
				return;
			}
		else
			{
				node* itr = head;
				for(int i =1 ;i<pos-1;i++)
				{
					itr = itr->next;
				}
				node* t = itr->next;
				itr->next = t->next;
				delete t;
			}		

	}
}
//TAKING INPUT
void buildList(node*&head)
{
	int data;
	cin >> data;
	while (data != -1)
	{
		add2tail(head, data);
		cin >> data;
	}
}

//PRINTING OUTPUT
void print(node* head)
{
	if (head == NULL)
		cout << "List is Empty!";
	else
	{
		while (head->next != NULL)
		{
			cout << head->data << " -> ";
			head = head->next;
		}
		cout << head->data;
	}
	cout << endl;
}
ostream& operator<<(ostream& os, node* head)
{
	print(head);
	return os;
}

istream& operator>>(istream& is, node*& head)
{
	buildList(head);
	return is;
}

node *kReverse (node *head, int k)  
{  
    node* current = head;  
    node* next = NULL;  
    node* prev = NULL;  
    int count = 0;  
      
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k)  
    {  
        next = current->next;  
        current->next = prev;  
        prev = current;  
        current = next;  
        count++;  
    }  
      
    /* next is now a pointer to (k+1)th node  
    Recursively call for the list starting from current.  
    And make rest of the list as next of first node */
    if (next != NULL)  
    head->next = kReverse(next, k);  
  
    /* prev is new head of the input list */
    return prev;  
}  
void detectAndRemoveLoop(node* &head)
{
 	unordered_set<int> node_set;
 	node* temp = head;
 	node* last = NULL;
 	while(temp != NULL)
 	{
 		if(node_set.find(temp->data)==node_set.end())
 		{
 			node_set.insert(temp->data);
 			last = temp;
 			temp = temp->next;
 		}
 		else
 		{
 			last->next = NULL;
 			break;
 		}
 	}
 	return;	
}
void segregateEvenOdd(node **head_ref)  
{  
    node *end = *head_ref;  
    node *prev = NULL;  
    node *curr = *head_ref;  
  
    /* Get pointer to the last node */
    while (end->next != NULL)  
        end = end->next;  
  
    node *new_end = end;  
  
    /* Consider all odd nodes before the first  
     even node and move then after end */
    while (curr->data % 2 == 0 && curr != end)  
    {  
        new_end->next = curr;  
        curr = curr->next;  
        new_end->next->next = NULL;  
        new_end = new_end->next;  
    }  
  
    // 10->8->17->17->15  
    /* Do following steps only if  
    there is any even node */
    if (curr->data%2 != 0)  
    {  
        /* Change the head pointer to  
        point to first even node */
        *head_ref = curr;  
  
        /* now current points to 
        the first even node */
        while (curr != end)  
        {  
            if ( (curr->data) % 2 != 0 )  
            {  
                prev = curr;  
                curr = curr->next;  
            }  
            else
            {  
                /* break the link between 
                prev and current */
                prev->next = curr->next;  
  
                /* Make next of curr as NULL */
                curr->next = NULL;  
  
                /* Move curr to end */
                new_end->next = curr;  
  
                /* make curr as new end of list */
                new_end = curr;  
  
                /* Update current pointer to 
                next of the moved node */
                curr = prev->next;  
            }  
        }  
    }  
  
    /* We must have prev set before executing  
    lines following this statement */
    else prev = curr;  
  
    /* If there are more than 1 odd nodes  
    and end of original list is odd then  
    move this node to end to maintain  
    same order of odd numbers in modified list */
    if (new_end != end && (end->data) % 2 == 0)  
    {  
        prev->next = end->next;  
        end->next = NULL;  
        new_end->next = end;  
    }  
    return;  
}  
int main()
{
	node* head= NULL;

 	int n;
 	cin>>n;
 	for(int i=0;i<n;i++)
 	{
 		int x;
 		cin>>x;
 		add2tail(head,x);
 	}

 	segregateEvenOdd(&head);
	cout<<head;		

}
