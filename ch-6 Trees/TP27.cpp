/*
  Problem 27: Finding LCA in a BTree
  Time Complexity: O(n)
  Space Complexity: O(n)
**/

#include<iostream>
#include<stdlib.h>
#include<queue>
#include<vector>
using namespace std;

/*
defining the structure
**/
typedef struct Tree {
  char data;
  struct Tree *left, *right;
}BTree;

BTree* initializeNode () {
  BTree *root = (BTree*) malloc (sizeof (BTree));
  if (!root)  return NULL;
  root->left = root->right = NULL;
  return root;
}
void preOrder (BTree *root) {
  if (root) {
    cout<<root->data<<" ";
    preOrder (root->left);
    preOrder (root->right);
  }
}
void inOrder (BTree *root) {
  if (root) {

    inOrder (root->left);
    cout<<root->data<<" ";
    inOrder (root->right);
  }
}
int search (char inOrder[], int start,int end, char c) {
  int i=0;
  for(i = start; i <= end; i ++) {
    if (inOrder[i] == c)
      return i;
  }
  return 0;
}

BTree * buildTree (char preOrder[], int start, char inOrder[], int end) {

  static int preIndex = 0;
  if (start > end)
    return NULL;

  BTree *node = initializeNode ();
  node->data = preOrder[preIndex++];
  if (start == end)
    return node;
  int inIndex = search (inOrder, start,end, node->data);

  node->left = buildTree (preOrder, start, inOrder, inIndex-1);
  node->right = buildTree (preOrder, inIndex+1, inOrder, end);
  return node;
}
int main (void) {
  BTree *root = NULL;
  char inOrderStr[] = {'D','B','E','A','F','C'};
  char preOrderStr[] = {'A','B','D','E','C','F'};
  int len = sizeof(preOrderStr)/sizeof(preOrderStr[0]);
  root = buildTree (preOrderStr, 0, inOrderStr, len-1);
  cout<<"\nPreOrder Traversal:";
  preOrder(root);
  cout<<"\nInOrder Traversal:";
  inOrder(root);
  cout<<endl;
  return 0;
}
