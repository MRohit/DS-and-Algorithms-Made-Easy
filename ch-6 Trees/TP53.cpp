/*
  Problem 53: Check if given tree is BST
  Time Complexity: O(n)
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
}BSTree;

BSTree* initializeNode () {
  BSTree *root = (BSTree*) malloc (sizeof (BSTree));
  if (!root)  return NULL;
  root->left = root->right = NULL;
  return root;
}

void inOrder (BSTree *root) {
  if (root) {

    inOrder (root->left);
    cout<<root->data<<" ";
    inOrder (root->right);
  }
}

BSTree *createBST (BSTree *root, int data) {
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
int findMin (BSTree *root) {
  if (!root)
    return 0;
  if (root->left == NULL)
    return root->data;
  else
    return findMin (root->left);
}
int findMax (BSTree *root) {
  if (!root)
    return 0;
  if (root->right == NULL)
    return root->data;
  else
    findMax (root->right);
}
int isBST (BSTree *root, int *prev) {
  if (root == NULL)
    return 1;
  if (!isBST (root->left, prev))
    return 0;
  if (root->data < *prev)
    return 0;
  *prev = root->data;
  return isBST (root->right, prev);
}
int main (void) {
  BSTree *root = NULL;
  int arr[] = {50, 20, 10, 30, 90, 70,60,75, 100, 110, 105};
  int n = sizeof (arr) / sizeof (arr[0]);
  for (int i = 0; i < n; i++) {
    root = createBST (root, arr[i]);
  }

  cout<<"\n Inorder traversal for tree:";
  inOrder(root);
  int prev = 0;
  cout<<"\nIs BST:"<<isBST (root, &prev);
  cout<<endl;
  return 0;
}
