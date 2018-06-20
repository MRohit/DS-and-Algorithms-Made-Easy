/*
  Problem 39: Given parent array, find a maximum depth of tree
  Time Complexity: O(n^2)
  Space Complexity: O(1)
**/

#include<iostream>
#include<stdlib.h>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

int getDepth (int parent[], int n) {
  int maxDepth = -1, currentDepth = -1, j = 0;

  for (int i = 0; i < n; i++) {
    currentDepth = 0;
    j = i;
    while (parent[j] != -1) {
      ++ currentDepth;
      j = parent[j];
    }

    if (currentDepth > maxDepth)
      maxDepth = currentDepth;
  }
  return maxDepth;
}

int main (void) {
  int parent [] = {-1, 0, 1, 6, 6, 0, 0, 2, 7};
  int n = sizeof (parent) / sizeof (parent[0]);
  cout<<"\nMaximum depth of tree:"<<getDepth (parent, n)<<endl;
  return 0;
}
