/*
  Problem 28: Remove adjacent duplicate characters from string
  Time Complexity: O(n)
  Space Complexity: O(1)

**/

#include<iostream>
#include<stdlib.h>
using namespace std;

void removeAdjacentDuplicate (char str[]) {
  int i = 0, stackPtr = -1, len = strlen (str);
  while (str[i] != '\0') {
    if (stackPtr == -1 || str[i] != str[stackPtr]) {

      stackPtr ++;
      str[stackPtr] = str[i];
      i ++;
    } else {
      while (i < len && str[stackPtr] == str[i])
        i++;
      stackPtr --;
    }
  }
  str[stackPtr + 1] = '\0';
  cout<<"\nAfter removing adjacent duplicates:"<<str;
}
int main (void) {
  char str [] = "careermonk";
  removeAdjacentDuplicate (str);
  cout<<endl;
  return 0;
}
