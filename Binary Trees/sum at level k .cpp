
#include<bits/stdc++.h>
#define mp make_pair
#define psi pair<string,int>
#define f(n) for(int i=0;i<n;i++)
using namespace std;


class node {
public :
    int noOfChildren ;
    int data ;
    node(int d,int n) {
        data = d ;
        noOfChildren = n ;
        right = left = NULL ;
    }
    node *right ;
    node *left ;
};

void printPre(node*  root)
{
	if (root == NULL)
		return;

	cout << root->data << " ";
	printPre(root->left);
	printPre(root->right);
}



node* buildTreeGeneric(node* root){
    int d,n ;
    cin >> d >> n;
    root = new node(d,n);
    if(n==0){
        return root ;
    }
    else if(n==1){
        root->left = buildTreeGeneric(root->left);
        return root ;
    }
    else {
        root->left = buildTreeGeneric(root->left);
        root->right = buildTreeGeneric(root->right) ;
        return root ;
    }
}

int KthSum(node* root, int k, int sum = 0)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 0)
	{
		return root->data;
	}
	sum += KthSum(root->left, k - 1);
	sum += KthSum(root->right, k - 1);

	return sum;
}
int main()
{
	node* root=NULL;
	root = buildTreeGeneric(root);
	int K;
	cin >> K;
	cout << KthSum(root, K);
	return 0;
}
