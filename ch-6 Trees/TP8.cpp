/*
  Problem 8: Print Level order traversal in reverse order
  Time Complexity: O(n)
  Space Complexity: O(n)
**/

#include<iostream>
#include<stdlib.h>
#include<queue>
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

void insertNode (BTree **root, int data) {
  Queue *q = initializeQueue (20);
  BTree *node = initializeNode ();
  node->data = data;
  if (*root == NULL)
    *root = node;
  else {
    enQueue (q, *root);
    while (!isEmpty (q)) {
      BTree *temp = deQueue (q);
      if (temp->left)
        enQueue (q, temp->left);
      else {
        temp->left = node;
        deleteQueue (q);
        return;
      }

      if (temp->right)
        enQueue (q, temp->right);
      else {
        temp->right = node;
        deleteQueue (q);
        return;
      }
    }
  }
  deleteQueue (q);
}
void preOrder (BTree *root) {
  if (root) {
    cout <<root->data<< " ";
    preOrder (root->left);
    preOrder (root->right);
  }
}
void reverseLevelOrderTraversal (BTree *root) {
  Queue *q = initializeQueue (20);
  stack <int> st;

  if (root == NULL)
    return ;
  enQueue (q, root);
  while (!isEmpty (q)) {
    BTree *temp = deQueue (q);
    st.push (temp->data);
    if (temp->left)
      enQueue (q, temp->left);
    if (temp->right)
      enQueue (q, temp->right);

  }
  deleteQueue (q);
  while (!st.empty()) {
    cout<<st.top()<<" ";
    st.pop();
  }
}
int main (void) {
  BTree *root = NULL;
  insertNode (&root, 1);
  insertNode (&root, 2);
  insertNode (&root, 3);
  insertNode (&root, 4);
  insertNode (&root, 5);
  insertNode (&root, 6);

  cout<<"\nPreorder Traversal:";
  preOrder (root);
  cout<<"\n Reverse level order traversal:";
  reverseLevelOrderTraversal (root);
  cout<<endl;
  return 0;
}
