
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

//Helper Function
void printAtLevelK(node* root, int k)
{
	if (root == NULL)
		return;

	if (k == 0)
	{
		cout << root->data << " ";
		return;
	}
	printAtLevelK(root->left, k - 1);
	printAtLevelK(root->right, k - 1);
	return;
}
int printAtDistanceK(node* root, node* target, int k)
{
	//base case
	if (root == NULL)
		return -1;

	//reach the target node
	if (root == target)
	{
		printAtLevelK(target, k);
		return 0;
	}

	//Ancestor

	int DL = printAtDistanceK(root->left, target, k);

	if (DL != -1)
	{
		//Ancestor itself
		if (DL + 1 == k)
			cout << root->data << " ";

		else
		{
			printAtLevelK(root->right, k - 2 - DL);
		}
		return 1 + DL;
	}

	int DR = printAtDistanceK(root->right, target, k);

	if (DR != -1)
	{
		//Ancestor itself
		if (DR + 1 == k)
			cout << root->data << " ";

		else
		{
			printAtLevelK(root->left, k - 2 - DR);
		}
		return 1 + DR;
	}
	return -1;
}


int size(node *root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return (size(root->left) + 1 + size(root->right));
	}
}
bool isBST(node *root, int minvalue, int maxvalue)
{
	if (root == NULL)
	{
		return true;
	}
	if (root->data >= minvalue && root->data <= maxvalue && isBST(root->left, minvalue, root->data) && isBST(root->right, root->data, maxvalue))
	{
		return true;
	}
	return false;
}
int largestBST(node *root)
{
	//u don't have to return u have to check for all possible BST and then return the max
	if (isBST(root, INT_MIN, INT_MAX))
	{
		return size(root);
	}
	else
	{
		return max(largestBST(root->left), largestBST(root->right));
	}
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

int replaceSum(node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL and root->right == NULL)
	{
		return root->data;
	}
	//Recursive Part
	int leftSum = replaceSum(root->left);
	int rightSum = replaceSum(root->right);

	int temp = root->data;

	root->data = leftSum + rightSum ;
	return temp + root->data;
}
void modifyBSTUtil(node* root, int* sum)
{
	// Base Case
	if (root == NULL)
		return;

	// Recur for right subtree
	modifyBSTUtil(root->right, sum);

	// Now *sum has sum of nodes
	// in right subtree, add
	// root->data to sum and
	// update root->data
	*sum = *sum + root->data;
	root->data = *sum;

	// Recur for left subtree
	modifyBSTUtil(root->left, sum);
}

// A wrapper over modifyBSTUtil()
void modifyBST(node* root)
{
	int sum = 0;
	modifyBSTUtil(root, &sum);
}
void printGivenLevel(node* root, int level, int itr)
{
	if (root == NULL)
		return;
	if (level == 1)
		cout << root->data << " ";
	else if (level > 1)
	{
		if (!itr)
		{
			printGivenLevel(root->left, level - 1, itr);
			printGivenLevel(root->right, level - 1, itr);
		}
		else
		{
			printGivenLevel(root->right, level - 1, itr);
			printGivenLevel(root->left, level - 1, itr);
		}
	}
}
void printSpiral(node* root)
{
	int h = size(root); int i;
	bool itr = false;

	for (int i = 1; i <= h; i++)
	{
		printGivenLevel(root, i, itr);
		itr = !itr;
	}
}
int main()
{
	node* root = build("true");

//	replaceSum(root);
//	modifyBST(root);
//	printPre(root);
	printSpiral(root);

	return 0;
}
