/*
  Problem 30: Finding next greater element using stack
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
void nextGreatest (int arr[], int n) {
  stack *st = initializeStack (20);
  push (st, arr[0]);
  int nextGreater = -1;
  for (int i = 1; i < n; i ++) {
    nextGreater = arr[i];
    if (!isEmpty (st)) {
      int element = pop (st);
      while (element < nextGreater) {
        cout<<"\nFor the element "<< element << " nearest greater element is " << nextGreater;
        if (isEmpty (st))
          break;
        element = pop (st);
      }
      if (element > nextGreater)
        push (st, element);
    }
    push (st, nextGreater);
  }
  while (!isEmpty (st)) {
    int element = pop (st);
    nextGreater = -1;
    cout<<"\nFor the element "<< element << " nearest greater element is " << nextGreater;
  }
}
int main (void) {
  int arr [] = {5, 3, 2, 8, 6, 7, 11};
  int n = sizeof (arr) / sizeof (arr[0]);
  nextGreatest (arr, n);
  cout<<endl;
  return 0;
}
