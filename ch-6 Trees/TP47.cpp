/*
  Problem 47: Finding LCA in BST
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

BSTree *findLCA (BSTree *root, int a, int b) {
  if (!root)
    return NULL;
  if (a < root->data && root->data < b) {
    return root;
  } else if (root->data > a && root->data > b)
    return findLCA (root->left, a, b);
  else
    return findLCA (root->right, a, b);
}
int main (void) {
  BSTree *root = NULL;
  int arr[] = {50, 20, 10, 30, 40, 90, 70,60,75, 100, 110, 105};
  int n = sizeof (arr) / sizeof (arr[0]);
  for (int i = 0; i < n; i++) {
    root = createBST (root, arr[i]);
  }

  cout<<"\n Inorder traversal for tree:";
  inOrder(root);
  int a = 10, b = 40;
  cout<<"\nLCA of a:"<<a<<" b:"<<b<<" is:"<<(findLCA (root, a, b))-> data;
  cout<<endl;
  return 0;
}
