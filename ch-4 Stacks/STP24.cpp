/*
  Problem 24: Largest rectangle under histogram
  Time Complexity: O(n^2) Bruteforce
  Space Complexity: O(n) for stack

**/

#include<iostream>
#include<stdlib.h>
using namespace std;

int main (void) {
  int a[] = {4,8,3,2,0};
  int i = 0, j = 0, cnt = 0, temp = 0;
  for (i = 0; i < 5; i ++){
    cnt = 0;
    for (j = 0; j < 5;j ++){
      if (a[i] <= a[j]){
      cnt ++;
    }
  }
  if (temp < cnt * a[i])
    temp = cnt * a[i];
  }
  cout<<"\nLargest area:"<<temp<<endl;;
  return 0;
}
