/*
* Stack ADT implemention using dynamic Array
Time Complexity: 1. Push - O(1)
                 2. Pop - O(1)
                 3. isEmpty - O(1)
                 4. isFull - O(1)
                 5. getTop - O(1)
Space Complexity: O(n)
Performance issue: Too many doublings may cause memory overflow exception
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

/*
Method to initialize the stack
**/
stack *createStack (int cap) {
  stack* st = (stack*) malloc (sizeof (stack));
  if (!st)
    return NULL;
  st->cap = cap;
  st->top = -1;
  st->arr = (int*) malloc (sizeof (int) * cap);
  if (!st->arr)
    return NULL;
  cout<<"\nStack of size "<<st->cap<<" is created";
  return st;
}

/*
Method to check if stack is empty
**/
int isEmpty (stack *st) {
  return st->top == -1;
}

/*
Method to check if stack is full
**/
int isFull (stack *st) {
  return st->top == st->cap-1;
}

/*
Method to double the size of stack
**/
void doubleStack (stack *st) {
  cout<<"\nIncreasing Stack size";
  st->cap *= 2;
  st->arr = (int*) realloc (st->arr, st->cap);
  cout<<"\nNew Stack size:"<<st->cap;
}

/*
Method to push element in stack
**/
void push (stack *st, int data) {
  if (isFull (st)) {
    cout<<"\nStack is full\n";
    doubleStack (st);
  }
  st->arr[++st->top] = data;

}


/*
Method to pop element from stack
**/
int pop (stack *st) {
  if (isEmpty (st)) {
    cout<<"\nStack is empty\n";
    return -1;
  }
  return st->arr[st->top--];
}

/*
Method to get Top element of stack
**/
int getTop (stack *st) {
  return st->arr[st->top];
}

/*
Method to delete stack
**/
void deleteStack (stack *st) {
  if (st) {
    if (st->arr) {
      free (st->arr);
    }
    free (st);
    cout<<"\nStack deleted";
  }
}

int main (void) {
  stack *st = createStack (5);

  push (st, 1);
  push (st, 2);
  push (st, 3);
  push (st, 4);
  push (st, 5);

  // Check boundary condition
  push (st, 6);
  cout<<"\nTop element:"<<getTop (st) <<endl;
  cout<<"\nPop starts:";
  cout<<pop (st)<<endl;
  cout<<pop (st)<<endl;
  cout<<pop (st)<<endl;
  cout<<pop (st)<<endl;
  cout<<pop (st)<<endl;

  // Check boundary condition
  cout<<pop (st)<<endl;

  // delete the stack
  deleteStack (st);

  cout<<endl;
  return 0;
}
