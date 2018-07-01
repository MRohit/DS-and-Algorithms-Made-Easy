/*
  Problem 54: Convert BST into Circular DLL
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

void convertToCircularDLL (BSTree *root, BSTree *& head, BSTree *& prev) {
  if (!root)
    return;

  convertToCircularDLL (root->left, head, prev);
  root->left = prev;
  if (prev)
    prev-> right = root;
  else
    head = root;


  BSTree *right = root->right;
  head->left = root;
  root->right = head;

  prev = root;

  convertToCircularDLL (right, head, prev);
}

void printCircularDLL (BSTree *head) {
  BSTree *temp = head;
  do {
    cout<<temp->data<<" -> ";
    temp = temp->right;
  } while (temp != head);
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
  BSTree *head = NULL, *head2 = NULL, *prev = NULL;

  convertToCircularDLL (root, head2, prev);
  cout<<"\nPrinting Circular Doubly Linked List:";
  printCircularDLL(head2);

  cout<<endl;
  return 0;
}
