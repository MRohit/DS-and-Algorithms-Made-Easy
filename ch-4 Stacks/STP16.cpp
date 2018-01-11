/*
  Problem 16: Implement 3 stacks using one array
  Time Complexity: O(n)
  Space Complexity: O(n) for stack

**/
#include<iostream>
#include<stdlib.h>
using namespace std;
/*
defining the structure
**/
typedef struct dst{
  int top1;
  int top2;
  int middle;
  int cap;
  int *arr;
}dst;

dst* createStack (dst *s) {
  s = new dst ();
  s->top1 = -1;
  s->top2 = 11;
  s->cap = 12;
  s->middle = s->cap / 2;
  s->arr = new int (s->cap);
  return s;
}

int isEmptyFirstStack (dst *s) {
  return s->top1 == -1;
}
int isFullFirstStack (dst *s) {
  return s->top1 == s->cap/2;
}
void pushFirstStack (dst *s, int data) {
  if (isFullFirstStack (s))
    cout<<"\nOverflow top1:"<<s->top1<<" top2"<<s->top2;
  else
    s->arr[++s->top1] = data;
}
int popFirstStack (dst *s) {
  if (isEmptyFirstStack(s)) {
    cout<<"\nUnderflow";
    return -1;
  }
  return s->arr[s->top1--];
}
int isFullSecondStack (dst *s) {
  cout<<"\nIn FUll Top1:"<<s->top1<<" Top2:"<<s->top2;
  return s->top2 == s->middle;
}
int isEmptySecondStack (dst *s) {
    cout<<"\nTop1:"<<s->top1<<" Top2:"<<s->top2;
  return s->top2 == s->cap;
}
void pushSecondStack (dst *s, int data) {
  if (isFullSecondStack(s)) {
    cout<<"\nOverflow second";
    cout<<"\nTop1:"<<s->top1<<" Top2:"<<s->top2;
  }
  else
    s->arr[--s->top2] = data;
}
int popSecondStack (dst *s) {
  if (isEmptySecondStack(s)) {
    cout<<"\nUnderflow second";
    return -1;
  }
  return s->arr[s->top2++];
}
int isFullMiddleStack (dst *s) {
  return s->middle == s->top2;
}
int isEmptyMiddleStack (dst *s) {
  return s->middle == s->cap/2;
}
void pushMiddleStack (dst *s, int data) {
  if (isFullMiddleStack(s))
    cout<<"\nOverflow middle";
  else
    s->arr[s->middle++] = data;
}
int popMiddleStack (dst *s) {
  if (isEmptyMiddleStack(s)) {
    cout<<"\nUnderflow middle";
    return -1;
  }
  return s->arr[s->middle--];
}
int main (void) {
  dst *s = NULL;
  s = createStack (s);
  pushFirstStack (s, 1);
  pushFirstStack (s, 2);
  pushFirstStack (s, 3);
  pushFirstStack (s, 4);
  pushFirstStack (s, 5);
  pushFirstStack (s, 6);
  pushFirstStack (s, 7);
  pushFirstStack (s, 8);
  pushMiddleStack (s, 9);
  cout<<"\nTop1:"<<s->top1<<" Top2:"<<s->top2;
  pushSecondStack (s, 12);
  pushSecondStack (s, 11);
  pushSecondStack (s, 10);
  pushSecondStack (s, 9);
  pushSecondStack (s, 8);
  cout<<"\nTop1:"<<s->top1<<" Top2:"<<s->top2;
  cout<<"\n"<<popFirstStack (s);
  cout<<"\n"<<popFirstStack (s);
  cout<<"\n"<<popFirstStack (s);
  cout<<"\n"<<popFirstStack (s);
  cout<<endl;
  return 0;
}
