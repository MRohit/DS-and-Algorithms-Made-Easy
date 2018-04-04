/*
  Problem 24: Convert tree to its mirror tree
  Time Complexity: O(n)
  Space Complexity: O(n)
**/

#include<iostream>
#include<stdlib.h>
#include<queue>
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
  for (int i = 1; i < 6; i ++) {
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
void printPath (int path[], int len) {
  for (int i = 0; i < len; i ++) {
    cout<<path[i]<<" ";
  }
  cout<<endl;
}
BTree* convertIntoMirrorTree (BTree *root) {
  // recursively do preorder traversal and swap the child nodes
  if (root) {
    convertIntoMirrorTree (root->left);
    convertIntoMirrorTree (root->right);
    BTree *temp = root->left;
    root->left = root->right;
    root->right = temp;
  }
  return root;
}
int main (void) {
  BTree *root = NULL;
  int path[1000];
  insertNode (&root);
  cout<<"\nBefore mirroring, Preorder Traversal Tree 1:";
  preOrder (root);
  root = convertIntoMirrorTree (root);
  cout<<"\nAfter mirroring, Preorder Traversal Tree 1:";
  preOrder (root);
  cout<<endl;
  return 0;
}
