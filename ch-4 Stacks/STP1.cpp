/*
  Problem 1: Brackets balanced or not
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
Method to check if expression is balanced or not
**/
void isBalanced (char expr[]) {
  stack *st = initializeStack (20);
  int i = 0;
  while (expr[i] != '\0') {
    char c = expr[i];
    if (!isalpha (c)) {
      switch (c) {
        case '(':
          push (st, c);
        break;

        case '{':
          push (st, c);
        break;

        case '[':
          push (st, c);
        break;

        case ')':
          if (!isEmpty (st) && getTop (st) == '(') {
            char x = pop (st);
          } else {
            cout<<"\nNot balanced";
            return;
          }

        break;
        case '}':
          if (!isEmpty (st) && getTop (st) == '{') {
            char x = pop (st);
          } else {
            cout<<"\nNot balanced";
            return;
          }

        break;
        case ']':
          if (!isEmpty (st) && getTop (st) == '[') {
            char x = pop (st);
          } else {
            cout<<"\nNot balanced";
            return;
          }

        break;
      }
    }
    i ++;
  }
  if(!isEmpty(st))
    cout<<"\nNot balanced";
  else
    cout<<"\nBalanced";

}
int main (void) {
  char expr[] = "[a+{(c*d)+(e*f)}]]";
  isBalanced (expr);

  char expr2[] = "[a+{(c*d)+(e*f)}]";
  isBalanced (expr2);
  cout<<endl;
  return 0;
}
