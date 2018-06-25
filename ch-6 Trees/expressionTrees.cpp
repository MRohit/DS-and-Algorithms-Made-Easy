/*
  Building expression trees using postfix expression
  e.g. abc*+d/
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

void inOrder (BTree *root) {
  if (root) {

    inOrder (root->left);
    cout<<root->data<<" ";
    inOrder (root->right);
  }
}

BTree *buildExpressionTree (char expr[], int size) {
  stack <BTree*> st;
  for (int i = 0; i < size; i++) {
    if (isalpha (expr[i])) {
      BTree *node = initializeNode ();
      node->data = expr[i];
      st.push (node);
    } else {
      BTree *t2 = st.top();st.pop();
      BTree *t1 = st.top();st.pop();
      BTree *node = initializeNode ();
      node->data = expr[i];
      node->left = t1;
      node->right = t2;
      st.push (node);
    }
  }

  return st.top();
}
int main (void) {
  BTree *root = NULL;
  char ch[] = {'A','B','C','*','+','D','/'};
  int n = sizeof (ch) / sizeof (ch[0]);
  root = buildExpressionTree (ch, n);
  cout<<"\n Inorder traversal for tree:";
  inOrder(root);
  cout<<endl;
  return 0;
}
