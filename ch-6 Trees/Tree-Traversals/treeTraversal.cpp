/*
A Simple Binary Tree and its Traversal techniques
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

typedef struct Stack {
  int top,cap;
  BTree **arr;
}Stack;

Stack* initializeStack (int size) {
  Stack *st = (Stack*) malloc (sizeof (Stack));
  st->top = -1;
  st->cap = size;
  st->arr = (BTree**) malloc (sizeof (BTree*) * size);
  if (!st->arr)
    return NULL;
  return st;
}
int isStackEmpty (Stack *st) {
  return st->top == -1;
}
int isStackFull (Stack *st) {
  return st->cap == st->top + 1;
}

void push (Stack *st, BTree *data) {
  if (isStackFull (st))
    return;
  st->arr[++st->top] = data;
}
BTree *pop (Stack *st) {
  if (isStackEmpty(st))
    return NULL;
  return st->arr[st->top--];
}

void deleteStack (Stack *st) {
  if (st) {
    if (st->arr)
      free (st->arr);
    free (st);
  }
}
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
void preOrder (BTree *root) {
  if (root) {
    cout <<root->data<<" ";
    preOrder (root->left);
    preOrder (root->right);
  }
}

void inOrder (BTree *root) {
  if (root) {
    inOrder (root->left);
    cout <<root->data<<" ";
    inOrder (root->right);
  }
}

void postOrder (BTree *root) {
  if (root) {
    postOrder (root->left);
    postOrder (root->right);
    cout <<root->data<<" ";
  }
}

void insertNode (BTree **root) {
  Queue *q = initializeQueue (20);
  for (int i = 1; i < 10; i ++) {
    BTree *node = initializeNode ();
    node->data = i;
    if (*root == NULL)
      *root = node;
    else {
      BTree *front = q->arr[q->front];
      if (front->left == NULL) {
        front->left = node;
      } else if (front->right == NULL){
        front->right = node;
      }
      if (front->left && front->right){
        deQueue (q);
      }
    }
    enQueue (q, node);
  }
}

void nonRecursivePreOrder (BTree *root) {
  Stack *st = initializeStack (20);
  while (1) {
    while (root) {
      cout <<root->data<<" ";
      push (st, root);
      root = root->left;
    }
    if (isStackEmpty(st))
      return;
    root = pop (st);
    root = root->right;
  }
  deleteStack (st);
}

void nonRecursiveInOrder (BTree *root) {
  Stack *st = initializeStack (20);
  while (1) {
    while (root) {
      push (st, root);
      root = root->left;
    }
    if (isStackEmpty (st))
      return;
    root = pop (st);
    cout << root->data << " ";
    root = root->right;
  }
  deleteStack (st);
}

void nonRecursivePostOrder (BTree *root) {
  Stack *st1 = initializeStack (20);
  Stack *st2 = initializeStack (20);
  push (st1, root);
  while (!isStackEmpty (st1)) {
    BTree *node = pop (st1);
    push (st2, node);
    if (node->left)
      push (st1, node->left);
    if (node->right)
      push (st1, node->right);
  }
  while (!isStackEmpty (st2)) {
    cout<<pop(st2)->data<< " ";
  }
}
int main (void) {
  BTree *root = NULL;

  insertNode (&root);
  cout<<"\nRecursive Preorder Traversal:";
  preOrder (root);
  cout<<"\nNon Recursive Preorder Traversal:";
  nonRecursivePreOrder (root);
  cout<<"\nRecursive Inorder Traversal:";
  inOrder (root);
  cout<<"\nNon Recursive Inorder Traversal:";
  nonRecursiveInOrder (root);
  cout<<"\nRecursive PostOrder Traversal:";
  postOrder (root);
  cout<<"\nNon Recursive PostOrder Traversal:";
  nonRecursivePostOrder (root);
  cout<<endl;
  return 0;
}
