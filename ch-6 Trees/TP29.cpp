/*
  Problem 29: Printing all ancestors of a given node
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
  BTree **arr;
  int front, rear, cap, size;

}Queue;

Queue* initializeQueue (int size) {
  Queue *q = (Queue*) malloc (sizeof(Queue));
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
  return q->front == ((q->rear+1) % q->cap);
}

void resizeQueue (Queue *q) {
  int size = q->cap * 2;
  //q->size = size;
  q->arr = (BTree**) realloc (q->arr, q->cap);
  if (!q->arr)
    return;
  if (q->front > q->rear) {
    for (int i = 0; i < q->front; i ++) {
      q->arr[i+size] = q->arr[i];
    }
    q->rear = q->rear + size;
  }
}

void enQueue (Queue *q, BTree *data) {
  if (isFull(q)) {
    cout<<"Queue full, resizeQueue in progress";
    resizeQueue (q);
  }
  q->rear = (q->rear + 1) % q->cap;
  q->arr[q->rear] = data;
  if (q->front == -1)
    q->front = q->rear;
  q->size++;
}

BTree *deQueue (Queue *q) {
  if (isEmpty(q))
    return NULL;
  BTree *data = q->arr[q->front];
  if (q->front == q->rear)
    q->front = q->rear = -1;
  else
    q->front = (q->front + 1) % q->cap;
  q->size -- ;
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
  for (int i = 1; i <= 12; i++) {
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

int printAllAncestors (BTree *root, int data) {
  if (root) {
    if (root->data == data) {
      return 1;
    }
    if (printAllAncestors (root->left, data) || printAllAncestors (root->right, data)) {
      cout <<root->data<<" ";
      return 1;
    }
  }
  return 0;
}
int main () {
  BTree *root = NULL;
  insertNode (&root);
  cout<<"\n Preorder traversal:";
  preOrder(root);
  int ancestors = 10;
  cout<<"\nPrinting all ancestors of node:"<<ancestors<<endl;
  printAllAncestors (root, ancestors);
  cout<<endl;
  return 0;
}
