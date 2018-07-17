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
  struct Tree *left, *right;
}BSTree;

BSTree* initializeNode () {
  BSTree *root = (BSTree*) malloc (sizeof (BSTree));
  if (!root)  return NULL;
  root->left = root->right = NULL;
  return root;
}

int main (void) {
  
  cout<<endl;
  return 0;
}
