/*
  Problem 3: Postfix expression evaluation
  Time Complexity: O(n)
  Space Complexity: O(n) for stack

**/

#include<iostream>
#include<stdlib.h>
using namespace std;

void isPermissible (char str[]) {
  int scount = 0;
  int i = 0;
  while (str[i] != '\0') {

    if (str[i] == 'S')
      scount ++;
    else
      scount --;
      if (scount <= 0) {
        cout<<"\nString is not permissible";
        return;
      }
    i ++;
  }
  cout<<"\nString is permissible";
}

int main (void) {
  char str[] = "SSXSSX";
  isPermissible (str);

  char str2[] = "SSXSSXXXX";
  isPermissible (str2);
  cout<<endl;
  return 0;
}
