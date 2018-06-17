/*
  Problem 33: Construct special tree with given preorder traversal as "ILILL", where I is root and L is leaf
  Time Complexity: O(n)
  Space Complexity: O(n)
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

  char data;
  struct Tree *left, *right;
}BTree;

BTree* initializeNode () {
  BTree *root = (BTree*) malloc (sizeof (BTree));
  if (!root)  return NULL;
  root->left = root->right = NULL;
  return root;
}


BTree* constructTree (char *arr, int *i) {
  BTree *node = initializeNode ();
  node->data = arr[*i];
  // return if all characters are scanned from array
  if (arr == NULL) {
    free (node);
    return NULL;
  }
  // return if leaf node is encountered
  if (arr[*i] == 'L')
    return node;

  // recursively form left subtree
  *i = *i + 1;
  node->left = constructTree (arr, i);

  // recursively form right subtree
  *i = *i + 1;
  node->right = constructTree (arr, i);
  // return node
  return node;
}

void preOrder (BTree *root) {
  if (root) {
    cout<<root->data<<" ";
    preOrder (root->left);
    preOrder (root->right);
  }
}
int main (void) {
  char pre[] = {'I','L','I','L','L'};
  int n = sizeof(pre)/sizeof(pre[0]);
  int i = 0;
  BTree *root = constructTree (pre, &i);
  cout<<"\nPreorder Traversal:";
  preOrder (root);
  cout<<endl;
  return 0;
}
