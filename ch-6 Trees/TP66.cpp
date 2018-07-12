/*
  Problem 66: Print elements between k1 and k2 in given BST using BFS Traversal
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

void preorder (BSTree *root) {
  if (root) {
    cout<<root->data<<" ";
    preorder (root->left);

    preorder (root->right);
  }
}

void printElementsBetweenRange (BSTree *root, int k1, int k2) {
  queue<BSTree*> q;
  if (!root)
    return;
  q.push (root);
  while (!q.empty()) {
    BSTree *temp = q.front();
    q.pop();
    if (temp->data >= k1 && temp->data <= k2) {
      cout<<temp->data<<" ";
    }
    if (temp->left)
      q.push (temp->left);
    if (temp->right)
      q.push (temp->right);
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

int main (void) {
  BSTree *root = NULL, *root2 = NULL;
  int arr[] = {50, 20, 10, 30, 90, 70,60,75, 100, 110, 105};
  int n = sizeof (arr) / sizeof (arr[0]);
  for (int i = 0; i < n; i++) {
    root = createBST (root, arr[i]);
  }
  int k1 = 30, k2 = 100;
  cout<<"\n Preoder traversal for tree 1: ";
  preorder(root);
  cout<<"\nElements between k1:"<<k1<<" and k2:"<<k2<<" are:";
  printElementsBetweenRange (root, k1, k2);
  cout<<endl;
  return 0;
}
