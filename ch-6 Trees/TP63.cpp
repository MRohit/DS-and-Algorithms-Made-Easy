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
    prev->right = root;
  else
    head = root;

  BSTree *right = root->right;
  //head->left = root;
  //root->right = head;
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

BSTree *mergeDoublyLinkedList (BSTree *head1, BSTree *head2) {
  BSTree *node = NULL, *temp = NULL;
  node = initializeNode ();
  node->right = temp;
  node->left = NULL;
  temp = node;
  while (head1 != NULL && head2 != NULL) {
    if (head1->data == head2->data) {
      temp->right = head1;
      head1->left = temp;
      temp = temp->right;
      head1 = head1->right;
      head2 = head2->right;
    } else if (head1->data < head2->data) {
      temp->right = head1;
      head1->left = temp;
      temp = temp->right;
      head1 = head1->right;
    } else {
      temp->right = head2;
      head2->left = temp;
      temp = temp->right;
      head2 = head2->right;
    }
  }

  if (head1 != NULL) {
    temp->right = head1;
    head1->left = temp;
  } else if (head2 != NULL){
    temp->right = head2;
    head2->left = temp;
  }

  temp = node->right;
  free (node);
  return temp;
}

int getCount (BSTree *head) {
  BSTree *temp = head;
  int cnt = 0;
  while (temp != NULL) {
    cnt ++;
    temp = temp->right;
  }
  return cnt;
}

BSTree *convertSortedDLLToBST (BSTree **head, int n) {
  // base case
  if (n <= 0)
    return NULL;
  // recursively construct left subtree
  BSTree *left = convertSortedDLLToBST (head, n/2);

  // construct the node
  BSTree *node = initializeNode ();
  node->data = (*head)->data;
  // set pointer to left subtree
  node->left = left;
  // move to next node in DLL
  *head = (*head)->right;
  // recursively construct right subtree
  node->right = convertSortedDLLToBST (head, n-n/2-1);

  return node;
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
  BSTree *head1 = NULL, *prev1 = NULL, *head2 = NULL, *prev2 = NULL;
  // 1. Convert both BST into sorted doubly linked list
  convertBSTToSortedDLL (root, head1, prev1);
  cout<<"\nSorted DLL of Tree 1:";
  printDLL (head1);
  convertBSTToSortedDLL (root2, head2, prev2);
  cout<<"\nSorted DLL of Tree 1:";
  printDLL (head2);

  // 2. Merge both doubly linked list and maintain count.
  BSTree *head3 = mergeDoublyLinkedList (head1, head2);
  cout<<"\nMerged DLL:";
  printDLL (head3);

  // 3. Get count of number of elements of merged DLL
  int count = getCount (head3);

  // 4. Construct BST of newly merged sorted DLL
  BSTree *unionRoot = convertSortedDLLToBST (&head3,count);
  cout<<"\n Inorder traversal of union tree:";
  inOrder (unionRoot);
  cout<<endl;
  return 0;
}
