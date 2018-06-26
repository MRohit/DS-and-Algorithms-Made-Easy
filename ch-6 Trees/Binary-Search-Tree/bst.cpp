/*
  Creating a binary search tree
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

void inOrder (BTree *root) {
  if (root) {

    inOrder (root->left);
    cout<<root->data<<" ";
    inOrder (root->right);
  }
}

BTree *createBST (BTree *root, int data) {
  if (root == NULL) {
    root = initializeNode ();
    root->data = data;
  } else {
    if (data < root->data)
      root->left = createBST (root->left, data);
    else
      root->right = createBST (root->right, data);
  }
  return root;
}

BTree *findMin (BTree *root) {
  if (!root)
    return NULL;
  if (root->left == NULL)
    return root;
  else
    return findMin (root->left);
}

BTree *findMax (BTree *root) {
  if (!root)
    return NULL;
  if (root->right == NULL)
    return root;
  else
    return findMax (root->right);
}

BTree *findElementInBST (BTree *root, int data) {
  if (!root)
    return NULL;
  if (root->data < data)
    return findElementInBST (root->right, data);
  else if (root->data > data)
    return findElementInBST (root->left, data);
  return root;
}
int main (void) {
  BTree *root = NULL;
  int arr[] = {50, 20, 10, 30, 40, 90, 70,60,75, 100, 110, 105};
  int n = sizeof (arr) / sizeof (arr[0]);
  for (int i = 0; i < n; i++) {
    root = createBST (root, arr[i]);
  }

  cout<<"\n Inorder traversal for tree:";
  inOrder(root);
  cout<<"\n Min element in BST:"<<findMin(root)->data;
  cout<<"\n Max element in BST:"<<findMax(root)->data;
  cout<<"\n Find element in BST:"<<findElementInBST(root, 100)->data;
  cout<<endl;
  return 0;
}
