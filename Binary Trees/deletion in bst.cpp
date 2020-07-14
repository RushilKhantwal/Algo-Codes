
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
// node* buildTree(int in[], int pre[], int inStrt, int inEnd)
// {
// 	static int preIndex = 0;

// 	if (inStrt > inEnd)
// 		return NULL;

// 	/* Pick current node from Preorder
// 	traversal using preIndex
// 	and increment preIndex */
// 	node* tNode = new node(pre[preIndex++]);

// 	/* If this node has no children then return */
// 	if (inStrt == inEnd)
// 		return tNode;

// 	/* Else find the index of this node in Inorder traversal */
// 	int inIndex = search(in, inStrt, inEnd, tNode->data);

// 	/* Using index in Inorder traversal, construct left and
// 	right subtress */
// 	tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
// 	tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

// 	return tNode;
// }


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
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
		node* root = NULL;
		f(n) {
			int x;
			cin >> x;
			root = insert(root, x);
		}

		int m;
		cin >> m;


		for (int i = 0; i < m; i++)
		{
			int x;
			cin >> x;
			root = deleteInBST(root, x);
		}

		printPre(root);
	}

	return 0;
}
