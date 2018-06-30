/*
  Problem 48: Finding smallest between two nodes
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

int distanceFromRoot (BSTree *root, int x) {
  if (root->data == x)
    return 0;
  else if (root->data > x)
    return 1 + distanceFromRoot (root->left, x);
  else
    return 1 + distanceFromRoot (root->right, x);
}
int findSmallestDistance (BSTree *root, int a, int b) {
  // base conditon
  if (!root)
    return 0;
  // a and b are smaller than root then look in left sub tree
  if (root->data > a && root->data > b)
    return findSmallestDistance (root->left, a, b);
  // a and b are greater than root then look in right sub tree
  if (root->data < a && root->data < b)
    return findSmallestDistance (root->right, a, b);
  // we've lca node, find its distance from both a and b
  if (root->data >= a && root->data <= b)
    return distanceFromRoot (root, a) + distanceFromRoot (root, b);
}
int main (void) {
  BSTree *root = NULL;
  int arr[] = {50, 20, 10, 30, 40, 90, 70,60,75, 100, 110, 105};
  int n = sizeof (arr) / sizeof (arr[0]);
  for (int i = 0; i < n; i++) {
    root = createBST (root, arr[i]);
  }

  cout<<"\n Inorder traversal for tree:";
  inOrder(root);
  int a = 40, b = 105;
  //swap(a,b);
  cout<<"\nSmallest distance between a:"<<a<<" b:"<<b<<" is:"<<findSmallestDistance (root, a, b);
  cout<<endl;
  return 0;
}
