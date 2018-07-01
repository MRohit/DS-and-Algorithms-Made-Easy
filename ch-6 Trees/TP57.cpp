/*
  Problem 57: Build balanced BST using sorted array
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

BSTree *buildBalancedBST (int arr[], int left, int right) {
  if (left > right)
    return NULL;
  int mid;
  BSTree *node = initializeNode ();
  if (!node)
    return NULL;
  if (left == right) {
    node->data = arr[left];
  } else {
    mid = left + (right-left)/2;
    node->data = arr[mid];
    node->left = buildBalancedBST (arr, left, mid-1);
    node->right = buildBalancedBST (arr, mid + 1, right);
  }
  return node;
}
int main (void) {
  BSTree *root = NULL;
  int arr[] = {10,20,30,40,50,60,70,80,90,100};
  int n = sizeof (arr) / sizeof (arr[0]);
  root = buildBalancedBST (arr, 0, n-1);
  cout<<"\n Inorder traversal for balanced BST:";
  inOrder(root);
  cout<<endl;
  return 0;
}
