/*
Problem 9: Output true if each pair in queue consists of consecutive number
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
int checkPairWiseOrder (stack <int> st) {
  Queue *q = initializeQueue (20);
  int flag = 1;
  while (!st.empty()) {
    enQueue (q, st.top());
    st.pop();
  }
  while (!isEmpty (q)) {
    st.push (deQueue (q));
  }
  while (!st.empty()) {
    int n = st.top();
    st.pop();
    enQueue (q, n);
    if (!st.empty()) {
      int m = st.top();
      enQueue (q, m);
      st.pop();
      if (abs (n-m) != 1) {
        //cout <<"\nN:"<<n<<" M:"<<m<< " Abs:"<<abs (n-m);
        return 0;
      }
    }
  }
  while (!isEmpty (q)) {
    st.push (deQueue (q));
  }
  return 1;
}
int main (void) {
  stack <int> st;
  st.push (4);
  st.push (5);
  st.push (-2);
  st.push (-3);
  st.push (11);
  st.push (10);
  st.push (5);
  st.push (6);
  st.push (20);
  int flag = checkPairWiseOrder (st);
  if (flag == 1) {
    cout <<"\n Pairs are ordered";
  } else {
    cout <<"\nPairs are not ordered";
  }
  cout << endl;
  return 0;
}
