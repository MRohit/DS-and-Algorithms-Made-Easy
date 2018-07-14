/*
  Problem 69: Given two BSTs, check whether the elements of them are same or not
  Time Complexity: O(n+m)
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

void preorder (BSTree *root) {
  if (root) {
    cout<<root->data<<" ";
    preorder (root->left);

    preorder (root->right);
  }
}

void printElementsBetweenRange (BSTree *root, int k1, int k2) {
  if (root) {
    printElementsBetweenRange (root->left, k1, k2);
    if (root->data >= k1 && root->data <= k2) {
      cout<<root->data<<" ";
    }
    printElementsBetweenRange (root->right, k1, k2);
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

void insertIntoHash (BSTree *root, unordered_set <int> &s) {
  if (root) {
    insertIntoHash (root->left, s);
    s.insert (root->data);
    insertIntoHash (root->right, s);
  }
}
bool isSame (BSTree *root1, BSTree *root2) {
  if (!root1 && !root2)
    return true;
  if ((!root1 && root2) || (root1 && !root2))
    return false;
  unordered_set<int> s1, s2;
  insertIntoHash (root1, s1);
  insertIntoHash (root2, s2);
  return s1 == s2;
}
int main (void) {
  BSTree *root = NULL, *root2 = NULL;
  int arr[] = {50, 20, 10, 30, 90, 70,60,75, 100, 110, 105};
  int n = sizeof (arr) / sizeof (arr[0]);
  for (int i = 0; i < n; i++) {
    root = createBST (root, arr[i]);
  }

  cout<<"\n Preoder traversal for tree 1: ";
  preorder(root);
  int arr2[] = {50, 110, 10, 30, 70, 90,60,75, 100, 20, 105};
  int n2 = sizeof (arr2) / sizeof (arr2[0]);
  for (int i = 0; i < n2; i++) {
    root2 = createBST (root2, arr2[i]);
  }

  cout<<"\n Preoder traversal for tree 2: ";
  preorder(root2);

  cout<<"\nIf two BSTs are contain equal elements:"<<isSame (root, root2);
  cout<<endl;
  return 0;
}
