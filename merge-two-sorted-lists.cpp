#include<bits/stdc++.h>
using namespace std;
class node{
public:
	int data;
	node* next;
	node(int data)
	{
		this->data = data;
		this->next = NULL;
	}

};

node* reverse(node* &head)
{
	node* curr = head;
	node* sub  = head;
	node* prev = NULL;

	while(curr)
	{
		sub = sub->next;
		curr->next = prev;
		prev = curr;
		curr = sub;
	}
	head = prev;
	return head;
}
void addHead( node* &head,int data)
{
	if(head == NULL)
		{
			head = new node(data);
			return;
		}
	else
	{
		node* temp = new node(data);
		temp->next = head;
		head = temp;	
	}	
}
node* merge(node* a,node*b)
{
	if(a == NULL)
	return b;
	else if(b==NULL)
	return a;

	if(a->data < b->data)
	{
		a->next = merge(a->next,b);
		return a;
	}
	else
	{
		b->next = merge(a,b->next);
		return b;
	}
	return nullptr;
}
void print(node* head)
{
	if (head == NULL)
		cout << "List is Empty!";
	else
	{
		while (head->next != NULL)
		{
			cout << head->data << " ";
			head = head->next;
		}
		cout << head->data;
	}
	cout << endl;
}
ostream& operator<<(ostream& os,node* head)
{
	print(head);
	return os;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n1,n2;
		node* head1 = NULL,*head2=NULL;
		cin>>n1;
		for(int i =0;i<n1;i++)
		{
			int x;
			cin>>x;
			addHead(head1,x);
		}
		head1 = reverse(head1);
		cin>>n2;
		for(int i =0;i<n2;i++)
		{
			int x;
			cin>>x;
			addHead(head2,x);

		}
		head2 = reverse(head2);
		node* head3 = merge(head1,head2);
		cout<<head3;

	}
}
