/*
  Problem 18: Stack permutation possible or not
  Time Complexity: O(n)
  Space Complexity: O(n) for stack

**/

#include<iostream>
#include<stdlib.h>
#include<queue>
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

int main (void) {
  queue<int>
}
