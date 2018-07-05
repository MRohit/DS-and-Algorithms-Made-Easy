/*
  Problem 61: finding floor and ceil in BST
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

BSTree* findCeil (BSTree *root, int k) {
  stack<BSTree*> st;
  BSTree *temp = root;
  while (temp) {
    st.push (temp);
    temp = temp->left;
  }
  BSTree *prev = NULL;
  while (!st.empty()) {
    temp = st.top();
    st.pop();
    if (temp->data == k)
      return temp;
    if (temp->data <= k)
      prev = temp;

    temp = temp->right;
    while (temp) {
      st.push(temp);
      temp = temp->left;
    }
  }
  return prev;
}

BSTree *findFloor (BSTree *root, int k) {
  stack<BSTree*> st;
  BSTree *temp = root;
  while (temp) {
    st.push (temp);
    temp = temp->left;
  }

  while (!st.empty()) {
    temp = st.top();
    st.pop();
    if (temp->data == k)
      return temp;
    if (temp->data > k)
      return temp;

    temp = temp->right;
    while (temp) {
      st.push(temp);
      temp = temp->left;
    }
  }
  return NULL;
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
  int k = 35;
  BSTree *prev = NULL;
  cout<<"\nCeil:"<<findCeil (root, k)->data;
  cout<<"\nFloor:"<<findFloor (root, k)->data;
  cout<<endl;
  return 0;
}
