/*
  Problem 59: Convert Sorted SLL in BST using bottom up approach
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

typedef struct sll {
  int data;
  struct sll *next;
}sll;
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
void preorder (BSTree *root) {
  if (root) {
    cout<<root->data<<" ";
    preorder (root->left);
    preorder (root->right);
  }
}
void printSLL (sll *head) {
  sll *temp = head;
  while (temp != NULL) {
    cout<<temp->data<<"->";
    temp = temp->next;
  }
}
sll *insert (sll *head, int n) {
  sll *temp2 = NULL;
  for (int i = 1; i <= n; i++) {
    sll *temp = (sll*)malloc(sizeof(sll));
    temp->data = i;
    temp->next = NULL;
    if (head == NULL) {
      head = temp;
      temp2 = temp;
    } else {
      temp2->next = temp;
      temp2 = temp;
    }
  }
  return head;
}

BSTree *convertSLLToBalancedBST (sll **head, int start, int end) {
  if (start > end)
    return NULL;
  int mid = start + (end - start) / 2;
  BSTree *left = convertSLLToBalancedBST (head, start, mid - 1);
  BSTree *parent = initializeNode ();
  parent->data = (*head)->data;
  parent->left = left;
  (*head) = (*head)->next;

  parent->right = convertSLLToBalancedBST (head, mid + 1, end);
  return parent;
}
int main (void) {
  BSTree *root = NULL;
  int n = 10;
  sll *head = insert (head, n);
  cout<<"\nSorted Singly linked list:";
  printSLL(head);

  root = convertSLLToBalancedBST (&head, 0, n-1);
  cout<<"\n Inorder traversal for converted Balanced BST:";
  inOrder (root);
  cout<<"\n Preorder traversal for converted Balanced BST:";
  preorder (root);
  cout<<endl;
  return 0;
}
