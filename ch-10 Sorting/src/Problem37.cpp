#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAX 100000

typedef struct Tree{
   int data;
   struct Tree*left,*right;
}Tree;

Tree*insert(Tree*root,int data){
   if(!root){
      if(root==NULL){
         root=(Tree*)malloc(sizeof(Tree));

      }

      root->data=data;
      root->left=root->right=NULL;
   }else if(data<=root->data)
      root->left=insert(root->left,data);
   else
      root->right=insert(root->right,data);

   return root;
}
void inOrder(Tree*root){
   if(root){
      inOrder(root->left);
      cout<<root->data<<" ";
      inOrder(root->right);
   }
}
int main(){
   int a[]={7,5,3,4,2,9,1};
   int n=sizeof(a)/sizeof(a[0]);
   Tree *root=NULL;
   for(int i=0;i<n;++i)
      root=insert(root,a[i]);
   inOrder(root);
   cout<<endl;
   return 0;
}
