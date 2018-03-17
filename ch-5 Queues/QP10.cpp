/*
Problem 10: Rearrange queue elements by interleaving the first half of the list
            with the second half of the list.
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
  q->front = q->rear = -1;
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
  return ((q->rear + 1) % q->cap == q->front);
}

void resizeQueue (Queue *q) {
  int size = q->cap * 2;
  q->cap = size;

  q->arr = (int*) realloc (q->arr, q->cap);
  if (!q->arr)
    return;
  if (q->front > q->rear) {
    for (int i = 0; i < q->front; i ++) {
      q->arr[i + size] = q->arr[i];
    }
    q->rear = q->rear + size;
  }
}
void enQueue (Queue *q, int data) {
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

int deQueue (Queue *q) {
  if (isEmpty (q))
    return -1;
  int data = q->arr[q->front];
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

void rearrangeQueue (Queue *q) {
  stack <int> st;
  if (q->size % 2 != 0)
    return;
  int half = q->size / 2;
  for (int i = 0; i < half; i ++) {
    st.push (deQueue (q));
  }
  while (!st.empty()) {
    enQueue (q,st.top());
    st.pop();
  }
  for (int i = 0; i < half; i++) {
    enQueue (q, deQueue (q));
  }
  for (int i = 0; i < half; i ++) {
    st.push (deQueue (q));
  }
  while (!st.empty()) {
    enQueue (q, st.top());
    enQueue (q, deQueue (q));
    st.pop();
  }
  while (!isEmpty (q)) {
    cout<<deQueue(q)<<" ";
  }
}

int main (void) {
  Queue *q = initializeQueue (20);
  enQueue (q, 11);
  enQueue (q, 12);
  enQueue (q, 13);
  enQueue (q, 14);
  enQueue (q, 15);
  enQueue (q, 16);
  enQueue (q, 17);
  enQueue (q, 18);
  enQueue (q, 19);
  enQueue (q, 20);
  rearrangeQueue (q);
  cout <<endl;
  return 0;
}
