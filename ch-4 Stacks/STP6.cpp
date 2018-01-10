/*
  Problem 6: Track Minimum element in stack by improving space complexity
  Time Complexity: O(1)
  Space Complexity: O(n) for stack

**/

#include<iostream>
#include<stdlib.h>
using namespace std;

/*
defining the stack structure
**/
typedef struct stack{
  int *arr;
  int cap, top;
} stack;

/*
defining two structures, one for storing elements and other for tracking minimum element.
**/
typedef struct AdvancedStack {
  stack *originalStack;
  stack *minStack;
} AdvancedStack;

AdvancedStack *initializeStack (int cap) {
  AdvancedStack *st = (AdvancedStack*) malloc (sizeof (AdvancedStack));
  if (!st)
    return NULL;
  st->originalStack = (stack*) malloc (sizeof (stack));
  st->minStack = (stack*) malloc (sizeof (stack));
  st->originalStack->arr = (int*) malloc (sizeof (int) * cap);
  st->originalStack->cap = cap;
  st->originalStack->top = -1;
  st->minStack->arr = (int*) malloc (sizeof (int) * cap);
  st->minStack->cap = cap;
  st->minStack->top = -1;

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
  Method to push data into both stacks accordingly
**/
void advancedPush (AdvancedStack *st, int data) {
  if (isFull (st->originalStack)) {
    cout<<"\nStack is full";
  } else {
    push (st->originalStack, data);
    // for memory efficient, add element onto minStack only if minStack is empty or its top element is less than current
    if (isEmpty (st->minStack) || getTop (st->minStack) >= data) {
      push (st->minStack, data);
    }
  }
}
/*
  Method to pop data from both stacks accordingly
**/
int advancedPop (AdvancedStack *st) {
  int data;
  if (isEmpty (st->originalStack)) {
    cout <<"\nStack is empty";
    return -1;
  }
  data = pop (st->originalStack);
  // for memory efficient, pop element from minStack if current popped element from originalStack is equal to minStack's top element
  if (data == getTop (st->minStack))
    int min = pop (st->minStack);
  return data;
}
/*
  gets minimum element in stack in O(1)
**/
int getMinimum (AdvancedStack *st) {
  return getTop (st->minStack);
}
int main (void) {
  AdvancedStack *st = initializeStack (20);
  advancedPush (st, 5);
  advancedPush (st, 6);

  cout<<"\nMinimum Element:"<<getMinimum (st);
  advancedPush (st, 4);
  advancedPush (st, 8);
  cout<<"\nMinimum Element:"<<getMinimum (st);
  advancedPush (st, 3);
  advancedPush (st, 11);
  cout<<"\nMinimum Element:"<<getMinimum (st);

  advancedPop (st);
  advancedPop (st);
  cout<<"\nMinimum Element:"<<getMinimum (st);
  cout<<endl;
  return 0;
}
