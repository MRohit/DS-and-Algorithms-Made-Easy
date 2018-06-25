/*
  Building expression trees using postfix expression
  e.g. abc*+d/
**/

#include<iostream>
#include<stdlib.h>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

/*
defining the structure
**/
typedef struct Tree {

  int data;
  struct Tree *left, *right;
}BTree;

BTree* initializeNode () {
  BTree *root = (BTree*) malloc (sizeof (BTree));
  if (!root)  return NULL;
  root->left = root->right = NULL;
  return root;
}

void preOrder (BTree *root) {
  if (root) {
    cout<<root->data<<" ";
    preOrder (root->left);
    preOrder (root->right);
  }
}

int main () {
  BTree *root = NULL;
  insertNode (&root, false);
  cout<<"\n Preorder traversal for tree:";
  preOrder(root);
  BTree *node = root->left->right;
  cout<<"\nNode:"<<node->data;
  cout<<"\nInorder successor of:"<<node->data<<" is:"<< (inorderSuccessor (node)) ->data;
  cout<<endl;
  return 0;
}
