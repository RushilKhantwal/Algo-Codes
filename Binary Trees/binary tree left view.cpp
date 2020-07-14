
#include<bits/stdc++.h>
#define mp make_pair
#define psi pair<string,int>
#define f(n) for(int i=0;i<n;i++)
using namespace std;


class node {
public:
	int data;
	node*left;
	node*right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* build(string s) {
	if (s == "true") {
		int d;
		cin >> d;
		node*root = new node(d);
		string l;
		cin >> l;
		if (l == "true") {
			root->left = build(l);
		}
		string r;
		cin >> r;
		if (r == "true") {
			root->right = build(r);
		}
		return root;
	}
	return NULL;
}

node* insert(node* root, int key)
{
	if (root == NULL)
	{
		return new node(key);
	}

	if (root->data < key)
	{
		root->right = insert(root->right, key);
	}
	else
	{
		root->left = insert(root->left, key);
	}
	return root;
}


void printPre(node*  root)
{
	if (root == NULL)
		return;

	cout << root->data << " ";
	printPre(root->left);
	printPre(root->right);
}


// node* buildTreeGeneric(node*root) {
// 	int d, n ;
// 	cin >> d >> n;
// 	root = new node(d, n);
// 	if (n == 0) {
// 		return root ;
// 	}
// 	else if (n == 1) {
// 		root->left = buildTreeGeneric(root->left);
// 		return root ;
// 	}
// 	else {
// 		root->left = buildTreeGeneric(root->left);
// 		root->right = buildTreeGeneric(root->right) ;
// 		return root ;
// 	}
// }

void NODES(node* root, int s, int e) {

	if (root == NULL)
		return;

	NODES(root->left, s, e);

	if (root->data >= s and root->data <= e)
		cout << root->data << " ";

	NODES(root->right, s, e);

}

node* create(int in[], int pre[], int s, int e)
{
	static int i = 0;
	//base case
	if (s > e)
	{
		return NULL;
	}

	//Rec case
	node* root = new node(pre[i++]);
	if (s == e)
		return root;
	int index = -1;
	for (int j = s; j <= e; j++)
	{
		if (in[j] == pre[i])
		{
			index = j;
			break;
		}

	}
	root->left = create(in, pre, s, index - 1);
	root->right = create(in, pre, index + 1, e);

	return root;
}


void display(node * root)
{
	if (root == NULL)
	{
		return;
	}

	if (root->left)
		cout << root->left->data;
	else
		cout << "END";
	cout << " => ";
	cout << root->data << " <= ";
	if (root->right)
		cout << root->right->data;
	else
		cout << "END";
	cout << endl;
	display(root->left);
	display(root->right);

}
node* deleteInBST(node* root , int data)
{
	if (root == NULL)
		return NULL;

	if (root->data > data)
	{
		root->left = deleteInBST(root->left, data);
		return root;
	}
	else if (root->data == data)
	{
		//case 1: no children
		if (!root->left and !root->right)
		{
			return NULL;
		}

		//case 2: 1 child
		if (root->left != NULL and !root->right)
		{
			node* temp = root->left;
			delete root;
			return temp;
		}
		if (root->right != NULL and !root->left)
		{
			node* temp = root->right;
			delete root;
			return temp;
		}

		// case 3: 2 children
		node* replace = root->right;
		while (replace->left != NULL)
		{
			replace = replace->left;
		}
		root->data = replace->data;
		root->right = deleteInBST(root->right, replace->data);
		return root;
	}
	else {
		root->right = deleteInBST(root->right, data);
		return root;
	}
}

queue<node*>q;
int x = 0;
void insert(node*&root) {                                           //INSERTION FUNCTION

	if (x == 0) {
		x++;
		int k;
		cin >> k;
		root = new node(k);
		q.push(root);
		q.push(NULL);
	}

	while (q.size() != 1 or q.front() != NULL) {

		if (q.front() == NULL) {
			q.pop();
			q.push(NULL);
		}
		int d;

		cin >> d;
		if (d != -1) {
			q.front()->left = new node(d);
			q.push(q.front()->left);
		}

		cin >> d;
		if (d != -1) {
			q.front()->right = new node(d);
			q.push(q.front()->right);
		}

		q.pop();
	}

}

void printRightView(node* root, int level , int &maxlevel)
{
	if (root == NULL)
	{
		return;
	}
	if (maxlevel < level)
	{
		//discovered a new level
		cout << root->data << " ";
		maxlevel = level;
	}
	printRightView(root->left, level + 1, maxlevel);
	printRightView(root->right, level + 1, maxlevel);
}
int main()
{



	node* root = NULL;
	insert(root);
	//printPre(root);
	int maxlevel = -1;
	printRightView(root, 0, maxlevel);

	return 0;
}
