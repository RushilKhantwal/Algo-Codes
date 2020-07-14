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

	cout << root->data << ",";
	printPre(root->left);
	printPre(root->right);
}

bool isSame(node* root1,node* root2)
{
	//1. Both Empty
	if(!root1 and !root2)
		return true;
	//2. Both non-empty, compare them
	if(root1 and root2)
	{
		return(isSame(root1->left,root2->left)and isSame(root1->right,root2->right));
	}

	//3.one empty, one not ->false
	return false;
}
int main()
{
	node* root1 = build("true");
	node* root2 = build("true");


	//printPre(root1);
	return 0;

}
