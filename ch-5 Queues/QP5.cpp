/*
Problem 5: Reverse Queue using stack
Time Complexity:O(n)
Space Complexity: O(n)
**/

#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;

/*
defining the structure
**/
typedef struct Queue {
  int front, rear;
  int cap,size;
  int *arr;
}Queue;

Queue *initializeQueue (int size) {
  Queue *q = (Queue*) malloc (sizeof (Queue));
  q->front = -1;
  q->rear = -1;
  q->cap = size;
  q->size = 0;
  q->arr = (int*) malloc (sizeof (int) * size);
  if (!q->arr)
    return NULL;
  return q;
}
int isEmpty (Queue *q) {
  return q->front == -1;
}
int isFull (Queue *q) {
  return (q->rear + 1) % q->cap == q->front;
}
void enQueue (Queue *q, int data) {
  if (isFull (q)) {
    cout<<"\nQueue is full";
  } else {
    q->rear = (q->rear + 1) % q->cap;
    q->arr[q->rear] = data;
    if (q->front == -1) {
      q->front = q->rear;
    }
    q->size ++;
  }
}

int deQueue (Queue *q) {
  int data = -1;
  if (isEmpty (q)) {
    return -1;
  }
  data = q->arr[q->front];
  if (q->front == q->rear)
    q->front = q->rear = -1;
  else
    q->front = (q->front + 1) % q->cap;
    q->size --;
  return data;
}
int main (void) {
  Queue *q = initializeQueue (5);
  enQueue (q, 1);
  enQueue (q, 2);
  enQueue (q, 3);
  enQueue (q, 4);
  enQueue (q, 5);
  //cout<<"\nDeQueue:"<<deQueue(q);
  stack <int> st;
  while (!isEmpty (q)) {
    st.push (deQueue (q));
  }
  while (!st.empty()) {
    enQueue (q, st.top());
    st.pop();
  }
  cout<<"\nAfter reversing elements order in Queue, First element after DeQueue:"<<deQueue(q);
  cout<<endl;
  return 0;
}
