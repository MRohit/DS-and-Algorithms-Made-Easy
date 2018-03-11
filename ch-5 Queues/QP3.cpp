/*
Problem 3: Implement stack using two Queues
Time Complexity:
  Push Operation: O(1)
  Pop Operation: O(n)
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
  int cap,size;
  int *arr;
}Queue;

typedef struct Stack {
  Queue *q1, *q2;
}Stack;
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
void push (Stack *s1, int data) {
  if (isEmpty (s1->q1))
    enQueue (s1->q2, data);
  else
    enQueue (s1->q1, data);
}

int pop (Stack *s1) {
  int size,i = 0;
  if (isEmpty (s1->q2)) {
    size = s1->q1->size;
    i = 0;
    while (i < size - 1) {
      enQueue (s1->q2, deQueue (s1->q1));
      i++;
    }
    return deQueue (s1->q1);
  } else {
    size = s1->q2->size;
    i = 0;
    while (i < size - 1) {
      enQueue (s1->q1, deQueue (s1->q2));
      i++;
    }
    return deQueue (s1->q2);
  }
}
int main (void) {
  Queue *q = initializeQueue (5);
  enQueue (q, 1);
  enQueue (q, 2);
  enQueue (q, 3);
  enQueue (q, 4);
  enQueue (q, 5);
  cout<<"\nDeQueue:"<<deQueue(q);
  cout<<endl;
  Stack *s1 = (Stack*) malloc (sizeof (Stack));
  if (s1 == NULL) {
    cout<<"\nFailed to initialize stack";
  } else {
    s1->q1 = initializeQueue (10);
    s1->q2 = initializeQueue (10);
    push (s1, 1);
    push (s1, 2);
    push (s1, 3);
    push (s1, 4);

    cout<<"\nPop Operation:"<<pop (s1);
    cout<<"\nPop Operation:"<<pop (s1);
  }
  cout<<endl;
  return 0;
}
