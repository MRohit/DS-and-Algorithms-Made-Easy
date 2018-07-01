/*
  Problem 56: Convert Sorted DLL in BST
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

void convertToDLL (BSTree *root, BSTree *& head, BSTree *& prev) {
  if (!root)
    return;

  convertToDLL (root->left, head, prev);
  if (prev == NULL) {
    head = root;
  }else {
    root->left = prev;
    prev->right = root;
  }
  prev = root;
  convertToDLL (root->right, head, prev);
}

void printDLL (BSTree *head) {
  BSTree *temp = head;
  while (temp != NULL) {
    cout<<temp->data<<" -> ";
    temp = temp->right;
  }
}
int countDLLNodes (BSTree *head) {
  int count = 0;
  BSTree *temp = head;
  while (temp != NULL) {
    count ++;
    temp = temp->right;
  }
  return count;
}
BSTree* convertSortedDLLToBST (BSTree **head, int n) {
  if (n <= 0)
    return NULL;
  // recursively construct left subtree
  BSTree *left = convertSortedDLLToBST (head, n / 2);

  // point to current node
  BSTree *root = *head;
  root->left = left;
  // move to next node in DLL
  *head = (*head)->right;

  // build right subtree
  root->right = convertSortedDLLToBST (head, n-n/2-1);

  return root;

}

BSTree *sortedListToBST (BSTree *head) {
  int n = countDLLNodes (head);
  return convertSortedDLLToBST (&head, n);
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
  BSTree *head = NULL, *head2 = NULL, *prev = NULL, *root2 = NULL;

  convertToDLL (root, head2, prev);
  cout<<"\nPrinting Sorted Doubly Linked List:";
  printDLL(head2);

  cout<<"\nConverting Sorted Double Linked List to Binary Search Tree:";

  root2 = sortedListToBST (head2);
  cout<<"\n Inorder traversal for converted BST:";
  inOrder(root2);
  cout<<endl;
  return 0;
}
