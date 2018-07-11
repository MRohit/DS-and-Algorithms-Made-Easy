/*
  Problem 63: Finding Union and intersection of two BST's
  Time Complexity: O(n+m)
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

void convertBSTToSortedDLL (BSTree *root, BSTree *& head, BSTree *& prev) {
  if (!root)
    return;
  convertBSTToSortedDLL (root->left, head, prev);
  if(prev)
    head = prev;
  BSTree *right = root->right;
  head->left = root;
  root->right = head;
  prev = root;
  convertBSTToSortedDLL (right, head, prev);
}

void printDLL (BSTree *head) {
  BSTree *temp = head;
  while (temp != NULL) {
    cout<<temp->data<<" -> ";
    temp = temp->right;
  }
}
int main (void) {
  BSTree *root = NULL, *root2 = NULL;
  int arr[] = {50, 20, 10, 30, 90, 70,60,75, 100, 110, 105};
  int arr2[] = {50, 19, 10, 29, 90, 70,60,74, 101, 110, 105};
  int n = sizeof (arr) / sizeof (arr[0]);
  for (int i = 0; i < n; i++) {
    root = createBST (root, arr[i]);
  }
  int n2 = sizeof (arr2) / sizeof (arr2[0]);
  for (int i = 0; i < n2; i++) {
    root2 = createBST (root2, arr2[i]);
  }
  cout<<"\n Inorder traversal for tree 1: ";
  inOrder(root);
  cout<<"\n Inorder traversal for tree 2: ";
  inOrder(root2);
  BSTree *head1 = NULL, *prev = NULL;
  convertBSTToSortedDLL (root, head1, prev);
  cout<<"\nSorted DLL of Tree 1:";
  printDLL (head1);
  cout<<endl;
  return 0;
}
