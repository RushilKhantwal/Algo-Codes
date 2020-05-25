#include<iostream>
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

//FINDING THE KTH NODE FROM THE END OF THE LIST IN A  SINGLE PASS OF THE LIST
node* kthnode(node* &head, int k)
{
	node* fast = head;
	node* slow = head;

	for (int i = 0; i < k; i++)
	{
		fast = fast->next;
	}

	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

//REVERSING THE LINKED LIST
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

//REVERSING THE LINKED LIST RECURSIVELY
node* recursiveRev(node*&head)
{
	//Base Case
	if (head == NULL or head->next == NULL)
		return head;
	//Rec Case
	else
	{
		node* smallHead = recursiveRev(head->next);
		node* c = head;
		c->next->next = c;
		c->next = NULL;

		return smallHead;
	}
}

//OPERATOR OVERLOADING
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



//MERGING TWO SORTED LINKED LISTS
node* merge(node* head1, node* head2)
{
	node* head3 = NULL;
	while (head1 != NULL and head2 != NULL)
	{
		if (head1->data <= head2->data)
		{
			add2tail(head3, head1->data);
			head1 = head1->next;
		}
		else
		{
			add2tail(head3, head2->data);
			head2 = head2->next;
		}
	}
	while (head1 != NULL)
	{
		add2tail(head3, head1->data);
		head1 = head1->next;
	}
	while (head2 != NULL)
	{
		add2tail(head3, head2->data);
		head2 = head2->next;
	}

	return head3;
}
//MERGING TWO SORTED LINKED LIST RECURSSIVELY

node* mergeRec(node*a,node* b)
{
	if(a == NULL)
		return b;
	if(b == NULL)
		return a;

	//

	node* c;
	if(a->data<b->data)
	{
		c=a;
		c->next = mergeRec(a->next,b);
	}
	else
	{
		c=b;
		c= mergeRec(a,b->next);
	}
	return c;
}


//FIND THE MIDDLE OF THE LIST
node* midPointRunner(node* head)
{
	if (head == NULL or head->next == NULL)
	{
		return head;
	}
	else
	{
		node* slow = head;
		node* fast = head->next;
		while (fast != NULL and fast->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}

		return slow;
	}
}
//MERGESORT FOR LINKED LIST

node* mergeSort(node* &head)
{
	//Base Case
	if(head == NULL or head->next ==NULL)
	{
		return head;
	}
	//Recursive Case
	//1. FINDING THE MID-POINT
	node* mid = midPointRunner(head);

	node* a = head;
	node* b =  mid->next;
	mid->next = NULL;

	//2. RECURSIVELY SORTING

	a= mergeSort(a);
	b=mergeSort(b);

	//3. MERGING a AND b

	node* c = merge(a,b);

	return c;
}

//LINEAR SEARCHING THE LIST
void search(node* head,int data)
{
	if(head == NULL)
		return;
	else
	{
		while(head != NULL)
		{
			if(head->data == data)
			{
				cout<<"FOUND!";
				return;
			}
			head = head->next;
		}
		cout<<"NOT FOUND!";
	}	 
}

//FLOYD'S ALGORITHM FOR CYCLE DETECTION 

bool detectCycle(node* head)
{
	node* fast = head;
	node* slow = head;

	while(fast != NULL and fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;

		if(slow == fast)
		{
			return true;
		}
	}
	return false;
}
//REMOVE CYCLE HELPER FUNCTION
node* sendFastBack(node* head)
{
	node* fast = head;
	node* slow = head;

	while(fast != NULL and fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;

		if(slow == fast)
		{
			return fast;
		}
	}
    return head; //Redundant.....
}

//FLOYD'S CYCLE REMOVAL
void removeCycle(node*&head)
{
	node* fast = sendFastBack(head);
	node* slow = head;

	while(slow->next != fast->next)
	{
		slow = slow->next;
		fast = fast->next;
	}
	fast->next = NULL;
}


int main()
{
	node* head = NULL;

	cin>> head;
	cout<<head;
	head = mergeSort(head);
	cout<<head;
	int k;
	cin>>k;
	search(head,k);
	return 0;
}