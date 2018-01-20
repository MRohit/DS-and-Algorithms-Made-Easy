/*
  Problem 29: Finding next greatest element
  Time Complexity: O(n^2)
  Space Complexity: O(1)

**/

#include<iostream>
#include<stdlib.h>
using namespace std;

void nextGreatest (int arr[], int n) {
  int i = 0;
  for (int i = 0; i < n; i ++) {
    int nextGreater = -1;
    for (int j = i + 1; j < n; j ++) {
      if (arr[i] < arr[j]) {
        nextGreater = arr[j];
        break;
      }
    }
    cout<<"\nNext greater for "<<arr[i]<<" is "<<nextGreater;
  }
}
int main (void) {
  int arr [] = {5, 3, 2, 8, 6, 7, 11};
  int n = sizeof (arr) / sizeof (arr[0]);
  nextGreatest (arr, n);
  cout<<endl;
  return 0;
}
