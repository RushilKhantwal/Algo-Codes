//Balanced BST
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



void printPre(node*  root)
{
	if (root == NULL)
		return;

	cout << root->data << " ";
	printPre(root->left);
	printPre(root->right);
}

node* buildTreeFromArray(int* arr, int s, int e)
{
	//base case
	if (s > e)
	{
		return NULL;
	}

	//Recursive Case

	int mid = (s + e) / 2;
	node* root = new node(arr[mid]);
	root->left = buildTreeFromArray(arr, s, mid - 1);
	root->right = buildTreeFromArray(arr, mid + 1, e);

	return root;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int arr[n];
		f(n)
		cin >> arr[i];

		node* root = buildTreeFromArray(arr, 0, n - 1);
		printPre(root);
	}
	return 0;
}
