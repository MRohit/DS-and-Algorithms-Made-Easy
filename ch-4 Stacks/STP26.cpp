/*
  Problem 26: Identify if stack is growing downwards or upwards
  Time Complexity: O(1)
  Space Complexity: O(1)

**/

#include<iostream>
#include<stdlib.h>
using namespace std;

void growth (int *temp2) {
  int temp;
  cout<<"\nAddress of first variable:"<< &temp;
  cout<<"\nAddress of second variable:"<< &temp2;
  if (&temp < &(*temp2)) {
    cout<<"\nStack is growing downwards";
  } else {
    cout<<"\nStack is growning upwards";
  }
}
void testStack () {
  int temp;
  growth (&temp);
}
int main (void) {
  testStack ();
  cout<<endl;
  return 0;
}
