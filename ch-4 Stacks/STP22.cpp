/*
Problem 22: Stock span problem
Time Complexity: O(n^2)
Space Complexity: O(1)
**/
#include<iostream>
#include<stdlib.h>
using namespace std;

void calculateSpan (int arr[], int n) {
  int i, j, span[n];
  for (int i = 0; i < n; i ++) {
    j = 1;
    while (j <= i && arr[i] > arr[i-j]) {
      j ++;
    }
    span[i] = j;
  }

  for (int i = 0; i < n; i ++) {
    cout << span[i] << " ";
  }
}
int main (void) {
  int arr[] = {6, 3, 4, 5, 2};
  int n = sizeof (arr) / sizeof (arr[0]);
  calculateSpan (arr, n);
  cout<<endl;
  return 0;
}
