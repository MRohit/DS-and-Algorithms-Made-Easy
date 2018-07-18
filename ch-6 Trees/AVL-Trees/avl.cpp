/*
  Sample AVL Tree program and its operations
**/

#include<iostream>
#include<stdlib.h>
#include<queue>
#include<vector>
#include<stack>
#include<unordered_set>
//#include<bits/stdc++>
using namespace std;

/*
defining the structure
**/
typedef struct Tree {

  int data;
  int height;
  struct Tree *left, *right;
}AVLTree;

AVLTree* initializeNode () {
  AVLTree *root = (AVLTree*) malloc (sizeof (AVLTree));
  if (!root)  return NULL;
  root->left = root->right = NULL;
  return root;
}

// Balance Factor = (height of leftsubtree - height of rightSubtree)
int balanceFactor (AVLTree *root) {
  int lh, rh;
  if (root == NULL)
    return 0;
  if (root->left == NULL)
    lh = 0;
  else
    lh = root->left->height + 1;

  if (root->right == NULL)
    rh = 0;
  else
    rh = root->right->height + 1;
  return (lh - rh);
}


int main (void) {

  cout<<endl;
  return 0;
}
