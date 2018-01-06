/*
Problem 40: Josephus Circle
Time Complexity: O(n)
Space Complexity: O(1)
**/

#include<iostream>
#include<stdlib.h>
using namespace std;

/*
defining the structure
**/
typedef struct cll {
  int data;
  struct cll *next;

} cll;

/*
Method to create a circular linked list and implement a josephus circle algorithm
**/
void josephus () {
  cll *p = NULL, *q = NULL;
  int n = 0, m = 0;
  // 1. get number of nodes and mth value
  cout<<"\nEnter no of nodes:";
  cin>>n;
  cout<<"\nEter mth:";
  cin>>m;
  // 2. Create a circular linked list
  p = q = (cll*) malloc (sizeof(cll));
  p->data = 1;
  for (int i = 2; i <= n; i ++) {
    p->next = (cll*) malloc (sizeof(cll));
    p = p->next;
    p->data = i;
  }
  p->next = q;

  // 3. Eliminate every mth player as long as more than one player remains
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < m; j ++) {
      p = p->next;
    }
    // 4. eliminate the mth player
    p->next = p->next->next;
  }
  cout <<"\nElected member is:"<<p->data<<endl;
}

int recursiveJosephus (int n, int k) {
  if (n == 1)
    return 1;
  else
    return (recursiveJosephus (n - 1, k) + k - 1) % n + 1;
}

int main (void) {

  cout<<"\nUsing Non Recursive method:";
  josephus ();
  cout<<"\nJosephus using recursive:"<<recursiveJosephus (7, 3)<<endl;
  return 0;
}
