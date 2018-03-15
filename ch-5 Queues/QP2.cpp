/*
Problem 2: Implement queue using two stacks
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
  stack <int> s1,s2;
}Queue;

void enQueue (Queue *q, int data) {
  q->s1.push (data);
}
int deQueue (Queue *q) {
  int data = -1;
  if (!q->s2.empty()) {
    data = q->s2.top();
    q->s2.pop();

  } else {
    while (!q->s1.empty()) {
      q->s2.push (q->s1.top());
      q->s1.pop();
    }
    if (!q->s2.empty()) {
      data = q->s2.top();
      q->s2.pop();
    }

  }
  return data;
}
int main (void) {
  Queue *q = (Queue*) malloc (sizeof (Queue));
  enQueue (q,1);
  enQueue (q,2);
  enQueue (q,3);
  enQueue (q,4);
  cout<<"\nDeQueue:"<<deQueue(q);
  cout<<endl;
  return 0;
}
