/*
  Problem 2: Infix to Postfix conversion
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

/*
To check precedence of operators
**/
int precedence (char x) {
   if (x == '(')	return 0;
   if (x == '+' || x == '-')	return 1;
   if (x == '*' || x == '/')	return 2;
   return 3;
}

/*
Method to convert infix to postfix
**/
void infixToPostfix (char expr[]) {
  stack *st = initializeStack (20);
  int i = 0;
  while (expr[i] != '\0') {
    char c = expr[i];
    if (isalpha (c)) {
      cout<<c;
    } else if (c == '(') {
      push (st, c);
    } else if (c == ')') {
      while (!isEmpty (st) && getTop (st) != '(') {
        char x = pop (st);
        cout<<x;
      }
      pop (st);
    } else {
      while (!isEmpty (st) && (precedence (c) <= precedence (getTop (st)))) {
        cout<<pop (st);
      }
      push (st, c);
    }
    i ++;
  }

  while (!isEmpty (st)) {
    cout<<pop (st);
  }
}

int main (void) {
  char expr[] = "(a+b)*(c+d)";
  cout<<"\nExpression:"<<expr<<" Postfix:";
  infixToPostfix (expr);
  cout<<endl;
  char expr2[] = "a*b-(c+d)+e";
  cout<<"\nExpression:"<<expr2<<" Postfix:";
  infixToPostfix (expr2);
  cout<<endl;
  return 0;
}
