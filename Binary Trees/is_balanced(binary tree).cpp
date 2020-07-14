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

pair<int, bool> isBalanced(node* root)
{
	pair<int, bool> p ;
	//Base Case
	if (root == NULL)
	{
		p = mp(0, true);
		return p;
	}

	//Recursive Case
	pair<int, bool> left = isBalanced(root->left);
	pair<int, bool> right = isBalanced(root->right);

	if (abs(left.first - right.first) <= 1 and left.second and right.second)
	{
		p.second = true;
	}
	else
	{
		p.second = false;
	}
	p.first = max(left.first, right.first) + 1;

	return p;
}

void printPre(node*  root)
{
	if (root == NULL)
		return;

	cout << root->data << " ";
	printPre(root->left);
	printPre(root->right);
}

int main()
{
	node* root = build("true");
	pair<int, bool> p = isBalanced(root);
	if (p.second)
		cout << "true";
	else
		cout << "false";

	return 0;
}
