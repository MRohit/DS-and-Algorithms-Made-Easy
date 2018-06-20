/*
  Problem 40: Count number of childs for a given generic tree
  Time Complexity: O(n)
  Space Complexity: O(1)
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
  struct Tree *firstChild, *sibling;
}GTree;

typedef struct Queue {
  GTree **arr;
  int front, rear, cap, size;

}Queue;

Queue* initializeQueue (int size) {
  Queue *q = (Queue*) malloc (sizeof(Queue));
  q->front = q->rear = -1;
  q->cap = size;
  q->size = 0;
  q->arr = (GTree**) malloc (sizeof (GTree*) * size);
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
  q->arr = (GTree**) realloc (q->arr, q->cap);
  if (!q->arr)
    return;
  if (q->front > q->rear) {
    for (int i = 0; i < q->front; i ++) {
      q->arr[i+size] = q->arr[i];
    }
    q->rear = q->rear + size;
  }
}

void enQueue (Queue *q, GTree *data) {
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

GTree *deQueue (Queue *q) {
  if (isEmpty(q))
    return NULL;
  GTree *data = q->arr[q->front];
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

GTree* initializeNode () {
  GTree *root = (GTree*) malloc (sizeof (GTree));
  if (!root)  return NULL;
  root->firstChild = root->sibling = NULL;
  return root;
}

void insertNode (GTree **root) {
  Queue *q = initializeQueue (20);
  for (int i = 1; i <= 12; i++) {
    GTree *node = initializeNode ();
    node->data = i;
    if (*root == NULL) {
      *root = node;
      (*root)->sibling = NULL;
    }

    else {
      GTree *front = q->arr[q->front];
      if (front->firstChild == NULL)
        front->firstChild = node;
      else if (front->sibling == NULL)
        front->sibling = node;
      if (front->firstChild != NULL && front->sibling != NULL)
        deQueue (q);

    }
    enQueue (q, node);
  }
  deleteQueue (q);
}
void preOrder (GTree *root) {
  if (root) {
    cout<<root->data<<" ";
    preOrder (root->firstChild);
    preOrder (root->sibling);
  }
}
int getSiblingsCount (GTree *node) {
  int count = 0;
  node = node->firstChild;
  while (node) {
    count ++;
    node = node->sibling;
  }
  return count;
}
int main (void) {
  GTree *root = NULL;
  insertNode (&root);
  cout<<"\n Preorder traversal:";
  preOrder(root);
  cout<<"\nTotal Childrens of Node:"<<root->firstChild->data<<":"<<getSiblingsCount (root->firstChild);
  cout<<endl;
  return 0;
}
