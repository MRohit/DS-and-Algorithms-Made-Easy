/*
  Problem 30: Printing tree in zigzag traversal
  Time Complexity: O(n)
  Space Complexity: O(n) + O(n) for two stacks
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

void printZigzag (BTree *root) {
  if (!root)
    return;

  stack<BTree*> currentLevel;
  stack<BTree*> nextLevel;
  bool leftToRight = true;
  currentLevel.push (root);

  while (!currentLevel.empty()) {
    BTree *temp = currentLevel.top();
    currentLevel.pop();
    if (temp) {
      cout<< temp->data<<" ";
      if (leftToRight) {
        if (temp->left)
          nextLevel.push (temp->left);
        if (temp->right)
          nextLevel.push (temp->right);
      } else {
        if (temp->right)
          nextLevel.push (temp->right);
        if (temp->left)
          nextLevel.push (temp->left);
      }
    }

    if (currentLevel.empty()) {
      leftToRight = !leftToRight;
      swap (currentLevel, nextLevel);
    }
  }
}
int main () {
  BTree *root = NULL;
  insertNode (&root);
  cout<<"\n Preorder traversal:";
  preOrder(root);
  int ancestors = 10;
  cout<<"\nPrinting tree in zigzag traversal:";
  printZigzag (root);
  cout<<endl;
  return 0;
}
