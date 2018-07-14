/*
  Problem 70: Given two BSTs, check whether the elements of them are same or not using inorder traversal on
    both the trees at the same time
  Time Complexity: O(max(n,m))
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


bool isSame (BSTree *root1, BSTree *root2) {
  BSTree *temp1 = root1, *temp2 = root2;
  stack<BSTree*> st1, st2;
  while (temp1 || temp2) {
    if (temp1) {
      st1.push (temp1);
      temp1 = temp1->left;
    }
    if (temp2) {
      st2.push (temp2);
      temp2 = temp2->left;
    }
  }

  int flag = 0;
  while (!st1.empty() || !st2.empty()) {
    temp1 = st1.top();
    st1.pop();
    temp2 = st2.top();
    st2.pop();

    if (temp1->data != temp2->data)
      return false;
    temp1 = temp1->right;
    temp2 = temp2->right;
    while (temp1 || temp2) {
      if (temp1) {
        st1.push (temp1);
        temp1 = temp1->left;
      }
      if (temp2) {
        st2.push (temp2);
        temp2 = temp2->left;
      }
    }
  }
  return true;
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
