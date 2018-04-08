/*
  Problem 26: Finding LCA in a BTree
  Time Complexity: O(n)
  Space Complexity: O(n)
**/

#include<iostream>
#include<stdlib.h>
#include<queue>
#include<vector>
using namespace std;

/*
defining the structure
**/
typedef struct Tree {
  int data;
  struct Tree *left, *right;
}BTree;

typedef struct Queue {
  int front, rear;
  int cap,size;
  BTree **arr;
}Queue;

Queue *initializeQueue (int size) {
  Queue *q = (Queue*) malloc (sizeof (Queue));
  q->front = q->rear = -1;
  q->cap = size;
  q->size = 0;
  q->arr = (BTree**) malloc (sizeof (BTree*) * size);
  if (!q->arr)
    return NULL;
  return q;
}

int isEmpty (Queue *q) {
  return q->front == -1;
}
int isFull (Queue *q) {
  return ((q->rear + 1) % q->cap == q->front);
}

void resizeQueue (Queue *q) {
  int size = q->cap * 2;
  q->cap = size;

  q->arr = (BTree**) realloc (q->arr, q->cap);
  if (!q->arr)
    return;
  if (q->front > q->rear) {
    for (int i = 0; i < q->front; i ++) {
      q->arr[i + size] = q->arr[i];
    }
    q->rear = q->rear + size;
  }
}
void enQueue (Queue *q, BTree *data) {
  if (isFull (q)) {
    cout<<"\nQueue is full. Increasing Queue size";
    resizeQueue (q);
  }
    q->rear = (q->rear + 1) % q->cap;
    q->arr[q->rear] = data;
    if (q->front == -1)
      q->front = q->rear;
    q->size ++;

}

BTree* deQueue (Queue *q) {
  if (isEmpty (q))
    return NULL;
  BTree* data = q->arr[q->front];
  if (q->front == q->rear)
    q->front = q->rear = -1;
  else
    q->front = (q->front + 1) % q->cap;
  q->size --;
  return data;
}

void deleteQueue (Queue *q) {
  if (q) {
    if (q->arr)
      free (q->arr);
    free (q);
  }
}

BTree* initializeNode () {
  BTree *root = (BTree*) malloc (sizeof (BTree));
  if (!root)  return NULL;
  root->left = root->right = NULL;
  return root;
}
void insertNode (BTree **root) {
  Queue *q = initializeQueue (20);
  for (int i = 1; i < 12; i ++) {
    BTree *node = initializeNode ();
    node->data = i;
    if (*root == NULL)
      *root = node;
    else {
      BTree *front = q->arr[q->front];
      if (front->left == NULL)
        front->left = node;
      else if (front->right == NULL)
        front->right = node;
      if (front->left != NULL && front->right != NULL)
        deQueue (q);
    }
    enQueue (q, node);
  }
  deleteQueue (q);
}
void preOrder (BTree *root) {
  if (root) {
    cout<<root->data<<" ";
    preOrder (root->left);
    preOrder (root->right);
  }
}
bool getPath (BTree *root, vector<int> &path, int k) {
  if (root == NULL) return false;

  path.push_back(root->data);

  if(root->data == k)
    return true;

  if ((root->left && getPath (root->left, path, k)) || (root->right && getPath (root->right, path, k)))
    return true;

  path.pop_back();
  return false;
}
int findLCA (BTree *root, int nodeA, int nodeB) {
  vector<int> path1, path2;

  if (!getPath(root, path1, nodeA) || !getPath(root, path2, nodeB))
    return -1;

    int i = 0;
  for (i = 0; i < path1.size() && i < path2.size(); i++) {
    if (path1[i] != path2[i])
      break;
  }
  return path1[i-1];
}
BTree* findLCA_SingleTraversal (BTree *root, int nodeA, int nodeB) {
  if (root == NULL)
    return NULL;

  if (root->data == nodeA || root->data == nodeB)
    return root;

  BTree *left = findLCA_SingleTraversal (root->left, nodeA, nodeB);
  BTree *right = findLCA_SingleTraversal (root->right, nodeA, nodeB);

  if (left && right)
    return root;

  return (left != NULL) ? left : right;

}
int main (void) {
  BTree *root = NULL;
  insertNode (&root);
  preOrder (root);
  int nodeA = 8, nodeB = 11;
  cout<<"\nUsing Vector--> LCA of "<<nodeA<<" & "<<nodeB<<" is:"<<findLCA (root, nodeA, nodeB);
  cout<<"\nUsing Single Traversal--> LCA of "<<nodeA<<" & "<<nodeB<<" is:"<<(findLCA_SingleTraversal (root, nodeA, nodeB))->data;
  cout<<endl;
  return 0;
}
