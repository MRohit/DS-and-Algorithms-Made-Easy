
/*
  Problem 1: Checking whether K-th bit is Set or Not
**/
#include<iostream>
#include<stdlib.h>
using namespace std;

int main (void) {
  int n = 6, k = 2;

  if (n & (1 << (k-1)))
    cout<<"\nBit is SET";
  else
    cout<<"\nBit is NOT SET";

  return 0;
}
