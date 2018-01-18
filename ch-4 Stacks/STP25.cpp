/*
  Problem 25: Largest rectangle under histogram
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
void largestRectangle (int arr[], int n) {
  int area = 0, max_area = 0, i = 0;
  // 1. Create an empty stack
  stack *st = initializeStack (20);
  // 2. Start from first bar
  while (i < n) {
    if (isEmpty (st) || arr[getTop(st)] <= arr[i])
      push (st, i++);
    else {
      int tp = pop (st);
      area = arr[tp] * (isEmpty (st) ? i : i - getTop (st) - 1);

      if (max_area < area)
        max_area = area;

    }
  }
  while (!isEmpty (st)) {
    int tp = pop (st);
    area = arr[tp] * (isEmpty (st) ? i : i - getTop(st) - 1);

    if (max_area < area)
      max_area = area;
  }
  cout<<"\nMax Area:"<<max_area;
}
int main (void) {
  int arr[] = {6, 2, 5, 4, 5, 1, 6};
  int n = sizeof (arr) / sizeof (arr[0]);
  largestRectangle (arr, n);
  cout<<endl;
  return 0;
}
