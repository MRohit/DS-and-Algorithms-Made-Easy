/*
  Problem 10: Check if string is palindrome using stacks
  Time Complexity: O(n)
  Space Complexity: O(n/2) for stack

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

/*
Method to check if string is palindrome or not
**/
void isPalindrome (char str[]) {
  stack *st = initializeStack (20);
  int i = 0;
  while (str[i] != 'X') {
    push (st, str[i]);
    i ++;
  }
  i ++;
  while (str[i]) {
    if (isEmpty (st)  || str[i] != pop (st)) {
      cout<<"\nString is not Palindrome";
      return;
    }
    i ++;
  }
  cout<<"\nString is Palindrome";
}
int main (void) {
  char str[] = "bababXbabab";
  isPalindrome (str);

  char str2[] = "bababbXbabab";
  isPalindrome (str2);
  cout<<endl;
  return 0;
}
