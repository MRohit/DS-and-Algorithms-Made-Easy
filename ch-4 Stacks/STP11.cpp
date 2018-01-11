/*
  Problem 11: Reverse elements of stack using Push & Pop operations
  Time Complexity: O(n^2)
  Space Complexity: O(n) for stack

**/

#include<iostream>
#include<stdlib.h>
using namespace std;

/*
defining the structure
**/
typedef struct stack{
  int *arr;
  int cap, top;
} stack;

stack *initializeStack (int cap) {
  stack *st = (stack*) malloc (sizeof (stack));
  if (!st)  return NULL;
  st->cap = cap;
  st->top = -1;
  st->arr = (int*) malloc (sizeof (int) * cap);
  if (!st->arr) return NULL;
  return st;
}

int isEmpty (stack *st) {
  return st->top == -1;
}
int isFull (stack *st) {
  return st->top == st->cap - 1;
}

void push (stack *st,int data) {
  if (isFull (st)) {
    cout<<"\nStack is full";
  } else {
    st->arr[++st->top] = data;
  }
}

int pop (stack *st) {
  if (isEmpty (st)) {
    cout<<"\nStack is empty";
    return -1;
  }
  return st->arr[st->top--];
}
char getTop (stack *st) {
  return st->arr[st->top];
}
void deleteStack (stack *st) {
  if (st) {
    if (st->arr)
      free (st->arr);
    free (st);
  }
}

/*
Recursive function to push all popped elements at bottom of stack
**/
void insertIntoStack (stack *st, int data) {
  if (isEmpty (st)) {
    push (st, data);
  } else {
    int temp = pop (st);
    insertIntoStack (st, temp);

    push (st, temp);
  }
}

/*
Recursive function to pop all elements from stack and again insertIntoStack.
**/
void reverseStack (stack *st) {
  if (isEmpty (st))
    return;
  int temp = pop (st);
  reverseStack (st);
  insertIntoStack (st, temp);

}



int main (void) {
  stack *st = initializeStack (5);
  push (st, 1);
  push (st, 2);
  push (st, 3);
  push (st, 4);
  push (st, 5);

  reverseStack (st);

  cout<<endl;
  return 0;
}
