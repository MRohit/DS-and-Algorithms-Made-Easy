/*
* Stack ADT implemention using Linked List
Time Complexity: 1. Push - O(1)
                 2. Pop - O(1)
                 3. isEmpty - O(1)
                 4. getTop - O(1)
                 5. deleteStack - O(n)
Space Complexity: O(n)
**/

#include<iostream>
#include<stdlib.h>
using namespace std;

/*
defining the structure
**/
typedef struct ListNode{
  int data;
  struct ListNode *next;
} stack;

/*
Method to initialize the stack
**/
stack *createStack () {
  return NULL;
}

/*
Method to check if stack is empty
**/
int isEmpty (stack *st) {
  return st == NULL;
}

/*
Method to push element in stack
**/
void push (stack **st, int data) {
  stack *temp = (stack*) malloc (sizeof (stack));
  if (!temp)
    return ;
  temp->data = data;
  temp->next = *st;
  *st = temp;
}


/*
Method to pop element from stack
**/
int pop (stack **st) {
  if (isEmpty ( (*st))) {
    cout<<"\nStack is empty\n";
    return -1;
  }
  stack *temp = *st;
  int data = temp->data;
  *st = temp->next;
  free (temp);
  return data;
}

/*
Method to get Top element of stack
**/
int getTop (stack **st) {
  return (*st)->data;
}

/*
Method to delete stack
**/
void deleteStack (stack *st) {
  stack *temp = st;
  while (temp != NULL) {
    stack *t = temp;
    temp = temp->next;
    free (t);
  }
}

int main (void) {
  stack *st = createStack ();

  push (&st, 1);
  push (&st, 2);
  push (&st, 3);
  push (&st, 4);
  push (&st, 5);

  cout<<"\nTop element:"<<getTop (&st) <<endl;
  cout<<"\nPop starts:";
  cout<<pop (&st)<<endl;
  cout<<pop (&st)<<endl;
  cout<<pop (&st)<<endl;
  cout<<pop (&st)<<endl;
  cout<<pop (&st)<<endl;
  cout<<pop (&st)<<endl;
  // delete the stack
  deleteStack (st);

  cout<<endl;
  return 0;
}
