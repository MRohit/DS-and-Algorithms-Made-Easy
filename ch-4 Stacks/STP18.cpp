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

/*
Method to find if output is permutation combination of input using stack's push and pop operation.
**/
void isPossible (int nos[], int sequence [], int n) {

  queue <int> input;
  for (int i = 0;i < n; i ++) {
    input.push (nos[i]);
  }
  queue <int> output;
  for (int i = 0; i < n; i ++) {
    output.push (sequence[i]);
  }

  stack *st = initializeStack (20);
  while (!input.empty()) {
    int no = input.front ();
    input.pop ();
    if (no == output.front ()) {
      output.pop ();
      while (!isEmpty (st)) {
        if (getTop (st) == output.front ()) {
          //cout<<"\nPop:"<<
          pop (st);
          output.pop ();
        } else {
          break;
        }
      }
    } else {
      //cout<<"\nPush:"<<no;
      push (st, no);

    }
  }

  if (isEmpty (st) && input.empty ()) {
    cout<<"\nPossible";
  } else {
    cout<<"\nNot Possible";
  }

}
int main (void) {
  int nos[] = {1,2,3};
  int seq[] = {2,1,3};
  int n = 3;
  isPossible (nos, seq, n);

  int nos2[] = {1,2,3,4,5,6};
  int seq2[] = {1,5,4,6,2,3};
  n = 6;
  isPossible (nos2, seq2, n);
  cout<<endl;
  return 0;
}
