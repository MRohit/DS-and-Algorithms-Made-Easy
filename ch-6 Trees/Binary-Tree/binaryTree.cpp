/*
A Simple Binary Tree
**/

#include<iostream>
#include<stdlib.h>
#include<stack>
#include<queue>
using namespace std;

/*
defining the structure
**/
typedef struct Tree {
  int data;
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
    cout <<root->data<<" ";
    preOrder (root->left);
    preOrder (root->right);
  }
}
void insertNode (BTree **root, queue<BTree*> *, int data) {
  BTree *temp = initializeNode ();
  temp->data = data;
  if (*root == NULL) {
    *root = temp;
  } else {

    BTree *front = q.front ();
    if (!front->left)
      front->left = temp;
    else if (!front->right)
      front->right = temp;
    else
      q.pop();
  }
  q.push (&temp);
  //return root;
}

int main (void) {
  BTree *root = initializeNode ();
  queue <BTree*> q;
  insertNode (&root, q, 1);
  insertNode (&root, q, 2);
  insertNode (&root, q, 3);
  insertNode (&root, q, 4);
  insertNode (&root, q, 5);
  insertNode (&root, q, 6);

  preOrder (root);
  cout<<endl;
  return 0;
}
