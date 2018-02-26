/*
Simple Circular Queue
Time Complexity:
  enQueue: O(1)
  DeQueue: O(1)
  isEmpty: O(1)
  isFull: O(1)
  deleteQueue: O(1)
Space Complexity: O(n)
**/

#include<iostream>
#include<stdlib.h>
using namespace std;

/*
defining the structure
**/
typedef struct Queue {
  int front, rear;
  int cap;
  int *arr;
}Queue;

Queue *initializeQueue (int size) {
  Queue *q = (Queue*) malloc (sizeof (Queue));
  q->front = q->rear = -1;
  q->cap = size;
  q->arr = (int*) malloc (sizeof (int) * size);
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

void enQueue (Queue *q, int data) {
  if (isFull (q))
    cout<<"\nQueue is full";
  else {
    q->rear = (q->rear + 1) % q->cap;
    q->arr[q->rear] = data;
    if (q->front == -1)
      q->front = q->rear;
  }
}

int deQueue (Queue *q) {
  if (isEmpty (q))
    return -1;
  int data = q->arr[q->front];
  if (q->front == q->rear)
    q->front = q->rear = -1;
  else
    q->front = (q->front + 1) % q->cap;
  return data;
}

void deleteQueue (Queue *q) {
  if (q) {
    if (q->arr)
      free (q->arr);
    free (q);
  }
}

int main (void) {
  Queue *q = initializeQueue (5);
  enQueue (q, 1);
  enQueue (q, 2);
  enQueue (q, 3);
  enQueue (q, 4);
  enQueue (q, 5);

  // check full
  enQueue (q, 6);

  cout <<"\nDequeue:"<<deQueue (q)<<endl;
  return 0;
}
