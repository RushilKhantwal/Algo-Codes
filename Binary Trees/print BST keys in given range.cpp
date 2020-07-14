
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
int main()
{


	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		node* root = NULL;
		while (n--)
		{
			int x;
			cin >> x;
			root = insert(root, x);
		}
		int s, e;
		cin >> s >> e;
		cout << "# Preorder : ";
		printPre(root);
		cout << endl;
		cout << "# Nodes within range are : ";
		NODES(root, s, e);
		cout << endl;
	}

	return 0;
}
