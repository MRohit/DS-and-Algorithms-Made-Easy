/*
  Problem 58: Build balanced BST using sorted Singly Linked List
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

BSTree *buildBalancedBST (BSTree *head) {
  
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
