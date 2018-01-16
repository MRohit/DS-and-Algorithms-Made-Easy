/*
  Problem 23: Stocks Span Problem
  Time Complexity: O(n)
  Space Complexity: O(n) for stack

**/

#include<iostream>
#include<stdlib.h>
using namespace std;

/*
defining the structure
**/
typedef struct stack{
  char *arr;
  int cap, top;
} stack;

stack *initializeStack (int cap) {
  stack *st = (stack*) malloc (sizeof (stack));
  if (!st)  return NULL;
  st->cap = cap;
  st->top = -1;
  st->arr = (char*) malloc (sizeof (char) * cap);
  if (!st->arr) return NULL;
  return st;
}

int isEmpty (stack *st) {
  return st->top == -1;
}
int isFull (stack *st) {
  return st->top == st->cap - 1;
}

void push (stack *st,char data) {
  if (isFull (st)) {
    cout<<"\nStack is full";
  } else {
    st->arr[++st->top] = data;
  }
}

char pop (stack *st) {
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

void calculateSpan (int arr[], int n) {
  int span[n], i = 1;
  stack *st = initializeStack (20);

  push (st, 0);
  span[0] = 1;
  for (i = 1; i < n; i ++) {
    while (!isEmpty (st) && arr[getTop (st)] <= arr[i]) {
      pop (st);
    }
    span [i] = (isEmpty (st)) ? i + 1 : i - getTop (st) ;
    push (st, i);
  }

  for (i = 0; i < n; i ++) {
    cout<<span[i] << " ";
  }
}
int main (void) {
  int arr[] = {6, 3, 4, 5, 2};
  int n = sizeof (arr) / sizeof (arr[0]);
  calculateSpan (arr, n);
  cout<<endl;
  return 0;
}
