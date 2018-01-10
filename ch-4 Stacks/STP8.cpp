/*
  Problem 8: Check if string is palindrome or not
  Time Complexity: O(n)
  Space Complexity: O(1)

**/

#include<iostream>
#include<stdlib.h>
using namespace std;

void isPalindrome (char str[]) {
  int i = 0, j = strlen (str) - 1;

  while (i < j && str[i] == str[j]) {
    i ++;
    j --;
  }
  if (i ==  j) {
    cout<<"\nString is Palindrome";
  } else {
    cout<<"\nString is not Palindrome";
  }
}
int main (void) {
  char str1[] = "nitin", str2[] = "nitinn";
  isPalindrome (str1);
  isPalindrome (str2);
  cout<<endl;
  return 0;
}
