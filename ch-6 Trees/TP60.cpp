/*
  Problem 60: Finging kth smallest element in BST
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

BSTree* kthSmallestElement (BSTree *root, int k) {
  stack<BSTree*> st;
  int count = 1;
  BSTree *temp2 = root;
  while (temp2) {
    st.push (temp2);
    temp2 = temp2->left;
  }
  while (!st.empty()) {
    BSTree *temp = st.top();
    st.pop();
    if (count == k)
      return temp;
    count ++;
    if (temp->right != NULL) {
      temp = temp->right;
      while (temp != NULL) {
        st.push (temp);
        temp = temp->left;
      }
    }

  }
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
  int k = 5;
  cout<<"\nKth smallest element:"<<kthSmallestElement (root, k)->data;
  cout<<endl;
  return 0;
}
