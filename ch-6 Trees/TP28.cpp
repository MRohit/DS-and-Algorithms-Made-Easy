/*
  Problem 28: Constructing Tree using Inorder, post order and Level Order traversals
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
void inOrder (BTree *root) {
  if (root) {

    inOrder (root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
  }
}
int search (int in[], int start, int end, int value) {
  int i;
  for (i = 0; i <= end; i++) {
    if (in[i] == value)
      return i;
  }
  return -1;
}
BTree* buildUtil (int in[], int post[], int start, int end, int *postLastIndex) {
  // 1. return from recursion
  if (start > end)
    return NULL;
  // 2. Initialize node with current PreIndex and increment it
  BTree *node = initializeNode ();
  node->data = post[*postLastIndex];
  (*postLastIndex) --;
  if (start == end)
    return node;

  // 3. find the current node data in inorder
  int inIndex = search (in, start, end, node->data);
  // 4. Call recursively with inIndex + 1 and assign it as right subtree
  node->right = buildUtil (in, post, inIndex + 1, end, postLastIndex);
  // 5. Call recursively with inIndex - 1 and assign it as left subtree
  node->left = buildUtil (in, post, start, inIndex - 1, postLastIndex);

  return node;
}
BTree* buildTree (int in[], int post[], int end) {
  int postLastIndex = end;
  return buildUtil (in, post, 0, end, &postLastIndex);
}

int *extractKeys(int in[], int level[], int m, int n)
{
    int *newlevel = new int[m], j = 0;
    for (int i = 0; i < n; i++)
        if (search(in, 0, m-1, level[i]) != -1)
            newlevel[j] = level[i], j++;
    return newlevel;
}
BTree *buildTreeUsingLevelAndInOrderTra (int in2[], int level[], int start, int end, int n) {

  if (start > end)
    return NULL;
  BTree *node = initializeNode();
  node->data = level[0];

  if (start == end)
    return node;
  int inIndex = search (in2, start, end, node->data);

  int *llevel = extractKeys (in2, level, inIndex, n);

  int *rlevel = extractKeys (in2 + inIndex + 1, level, n-inIndex-1, n);

  node->left = buildTreeUsingLevelAndInOrderTra (in2, llevel, start, inIndex - 1, n);

  node->right = buildTreeUsingLevelAndInOrderTra (in2, rlevel, inIndex + 1, end, n);
  delete [] rlevel;
  delete []llevel;
  return node;
}
int main (void) {
  int in[]   = {4, 8, 2, 5, 1, 6, 3, 7};
  int post[] = {8, 4, 5, 2, 6, 7, 3, 1};

  int n = sizeof(in)/sizeof(in[0]);

  BTree *root = buildTree(in, post, n - 1);

  cout  << "In Order of the constructed tree : \n";
  inOrder(root);

  int in2 [] = {4, 8, 10, 12, 14, 20, 22};
  int level[] = {20, 8, 22, 4, 12, 10, 14};
  n = sizeof(in2)/sizeof(in2[0]);

  BTree *root2 = buildTreeUsingLevelAndInOrderTra (in2, level, 0, n-1, n);
  cout  << "\nIn Order tree constructed using level and inorder : \n";
  inOrder(root2);
  cout<<endl;
  return 0;
}
