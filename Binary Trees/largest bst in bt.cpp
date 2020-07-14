#include<iostream>
#include<limits.h>
using namespace std;
class node
{
  public:
  int data;
  node *left;
  node *right;
  node(int d)
  {
    data=d;
    left=NULL;
    right=NULL;
  }
};
node *convertBST(long long int preorder[1001],long long int inorder[1001],int start,int end)
{
  if(start>end)
  {
    return NULL;
  }
  static int i=0;
  node *root=new node(preorder[i]);
  int j=0;
  for(j=start;j<=end;j++)
  {
    if(preorder[i]==inorder[j])
    {
      break;
    }
  }
  i++;
  root->left=convertBST(preorder,inorder,start,j-1);
  root->right=convertBST(preorder,inorder,j+1,end);
  return root;
}
int size(node *root)
{
  if(root==NULL)
  {
    return 0;
  }
  else
  {
    return (size(root->left)+1+size(root->right));
  }
}
bool isBST(node *root,int minvalue,int maxvalue)
{
  if(root==NULL)
  {
    return true;
  }
  if(root->data>=minvalue && root->data<=maxvalue && isBST(root->left,minvalue,root->data) && isBST(root->right,root->data,maxvalue))
  {
    return true;
  }
  return false;
}
int largestBST(node *root)
{
    //u don't have to return u have to check for all possible BST and then return the max
  if(isBST(root,INT_MIN,INT_MAX))
  {
    return size(root);
  }
  else
  {
    return max(largestBST(root->left),largestBST(root->right));
  }
}
int main()
{
  long long int N;
  cin>>N;
  node *root=NULL;
  long long int preorder[1001],inorder[1001];
  for(int i=0;i<N;i++)
  {
    cin>>preorder[i];
  }
  for(int i=0;i<N;i++)
  {
    cin>>inorder[i];
  }
  root=convertBST(preorder,inorder,0,N-1);
  int y=largestBST(root);
  cout<<y;
	return 0;
}
