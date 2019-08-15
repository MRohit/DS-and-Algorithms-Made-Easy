
/*
  Problem 2: Setting and Toggling K-th bit
**/
#include<iostream>
#include<stdlib.h>
using namespace std;

int main (void) {
  int n = 48, k = 3;

  // right shift 1 by k - 1
  int one = 1 << (k-1);

  // do or with n
  n = n | one;

  cout<<"\n After setting k-th bit: "<<n<<endl;
  n = 48;
  // toggling k-th bit
  int toggle = 1 << (k-1);
  n = n ^ toggle;
  cout<<"\nAfter toggling kth bit: "<<n<<endl;

  return 0;
}
