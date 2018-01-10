/*
  Problem 3: Postfix expression evaluation
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
int calculate (int a, int b, char c){
  if (c == '+')	return a + b;
  if (c == '*')	return a * b;
  if (c == '/')	return a / b;
  if (c == '-')	return a - b;
  return 0;
}

/*
Method to evaluate postfix expression
**/
void evaluatePostfix (char expr []) {
  stack *st = initializeStack (20);
  int i = 0, op1 = 0, op2 = 0;
  while (expr[i] != '\0') {
    char c = expr [i];
    // if operand then push it on to the stack
    if (isdigit (c)) {
      push (st, c - 48);
    } else {
    // if operator, pop two operands, calculate the result and push it on to the stack
      op2 = pop (st);
      op1 = pop (st);
      push (st, calculate (op1, op2, c));
    }
    i++;
  }
  // print the result
  cout<<pop (st);
  deleteStack (st);
}
int main (void) {
  char expr[] = "123*+5-";
  cout<<"\nExpression:"<<expr<<" Result:";
  evaluatePostfix (expr);
  cout<<endl;
  return 0;
}
