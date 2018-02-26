/*
Linked List Queue
Time Complexity:
  enQueue: O(1)
  DeQueue: O(1)
  isEmpty: O(1)
  deleteQueue: O(n)
Space Complexity: O(n)
**/

#include<iostream>
#include<stdlib.h>
using namespace std;

/*
defining the structure
**/
typedef struct ListNode {
  int data;
  struct ListNode *next;
}ListNode;

typedef struct Queue {
  struct ListNode *front, *rear;
}Queue;

Queue * createQueue () {
  Queue *q = (Queue*) malloc (sizeof (Queue));
  ListNode *node = (ListNode*) malloc (sizeof (ListNode));
  if (!q)
    return NULL;
  q->front = q->rear = NULL;
  return q;
}
int isEmpty (Queue *q) {
  return (q->front == NULL);
}

void enQueue (Queue *q, int data) {
  ListNode *node = (ListNode*) malloc (sizeof (ListNode));
  if (!node)
    return;
  node->data = data;
  node->next = NULL;
  if (q->rear)  q->rear->next = node;
  q->rear = node;
  if (q->front == NULL)
    q->front = q->rear;
}

int deQueue (Queue *q) {
  int data = 0;
  if (isEmpty (q))
    return -1;
  ListNode *temp = q->front;
  data = temp->data;
  q->front = q->front->next;
  free (temp);
  return data;
}

void deleteQueue (Queue *q) {
  ListNode *temp;
  while (q) {
    temp = q->front;
    q->front = temp->next;
    free (temp);
  }
  free (q);
}

int main (void) {
  Queue *q = createQueue ();
  enQueue (q, 1);
  enQueue (q, 2);
  enQueue (q, 3);
  enQueue (q, 4);
  enQueue (q, 5);

  cout<<"\nDeQueue:"<<deQueue(q)<<endl;
  return 0;
}
