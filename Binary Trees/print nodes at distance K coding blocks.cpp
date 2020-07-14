//Tree Preorder & inorder
#include<iostream>
using namespace std;
#include<climits>
class node{
 public:
     int info;
     node*left;
     node*right;
     node(int d){
      info=d;
     }
};
 int k=0;
 //Select from preorder and search in order then divide it
   node*build(int P[],int I[],int s,int e){
       if(s>e){
        return NULL;
       }
       node*root;
         int num=P[k++];
            // search p[i] in I[]
            int j;
             for(j=s;j<=e;j++){
                if(num==I[j])
                  break;
              }
           root=new node(num);
              root->left=build(P,I,s,j-1);
              root->right=build(P,I,j+1,e);

    return root;
   }
   void Find(node*root,int k){
       if(root==NULL)
        return;
        if(k==0){
	        cout<<root->info<<" ";
		return;
		}
	   Find(root->left,k-1);
       Find(root->right,k-1);
   }
   void preorder(node*root){
     if(root==NULL)
        return;
     cout<<root->info;
     preorder(root->left);
     preorder(root->right);
  }
  int distk(node*root,int k,int inf){
      if(root==NULL)
        return -1;
     if(root->info==inf){
        Find(root->left,k-1);
        Find(root->right,k-1);
        return 0;
     }
     int l=distk(root->left,k,inf);
     if(l!=-1){
         if(l+1==k)
            cout<<root->info<<" ";
      else{
          Find(root->right,k-l-2);
      }
     return 1+l;
    }
    int r=distk(root->right,k,inf);
    if(r!=-1){
                 if(r+1==k)
            cout<<root->info<<" ";
      else{
          Find(root->left,k-r-2);
      }
     return 1+r;
    }
    return -1;
  }
  void printkdistancedown(node*root,int k)
  {
    if(root==NULL || k<0)
        return;
        if(k==0){
            cout<<root->info<<" ";
           return;
        }
    printkdistancedown(root->left,k-1);
    printkdistancedown(root->right,k-1);
 }
 int printkdistance(node*root,int target,int k)
 {
        if(root==NULL)
            return -1;
     if(root->info==target)
     {
        printkdistancedown(root,k);
        return 0;
     }
     int dl=printkdistance(root->left,target,k);
      if(dl!=-1)
      {
          if(dl+1==k)
          {
            cout<<root->info<<" ";
          }
          else
            printkdistancedown(root->right, k-dl-2);
       return 1+dl;
      }
     int dr=printkdistance(root->right,target,k);
     if (dr!=-1)
     {
         if (dr + 1 == k)
            cout << root->info << " ";
         else
            printkdistancedown(root->left, k-dr-2);
         return 1 + dr;
    }
    return -1;
 }
int main(){
   int inf,k,i,n,P[1000],m,I[1000];
   cin>>n;
   for(i=0;i<n;i++)
   {
     cin>>P[i];
   }
   for(i=0;i<n;i++)
   {
     cin>>I[i];
   }
  node*root=build(P,I,0,n-1);
 int t;
 cin>>t;
 while(t--)
 {
     cin>>inf;
     cin>>k;
      printkdistance(root,inf,k);
     cout<<endl;
   }
}
