/*
Problem 35: Split circular linked list into two parts
Time Complexity: O(n)
Space Complexity: O(1)
**/

#include<iostream>
#include<stdlib.h>
using namespace std;

/*
defining the structure
**/
typedef struct cll{
  int data;
  struct cll *next;
} cll;

/*
Method to insert data into linked list
**/
void insert (cll **head, int data) {
  cll *temp = *head, *newNode;
  newNode = (cll*) malloc (sizeof(cll));
  newNode->data = data;
  newNode->next = newNode;
  if (*head == NULL) {
    *head = newNode;
    return;
  } else {
    while (temp->next != *head) {
      temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
  }
}
void print (cll **head) {
  cll *temp = *head;
  if (*head == NULL)
   return;
  do {
    cout<<temp->data<<"->";
    temp = temp->next;
  } while (temp != *head);
}

/*
Method to divide the circular linked list into two parts
**/
void splitCircularList (cll **head) {
  // head1 for first half and head2 for second half
  cll *head1 = *head, *head2 = *head, *temp = NULL;
  cll *slow = *head, *fast = *head;
  while (fast->next != *head && fast->next->next != *head) {
    slow = slow->next;
    fast = fast->next->next;
    //cout<<"\nSlow:"<<slow->data<<"\tFast:"<<fast->data;
  }
  cout<<"\nSlow:"<<slow->data<<"\tFast:"<<fast->data;
  // make second half circular
  if (fast->next->next == *head)
    fast = fast->next;

  if ((*head)->next != *head)
    head2 = slow->next;

  fast->next = slow->next;
  cout<<"\nSecond half:";
  print (&head2);

  // make first half circular
  slow->next = *head;
  cout<<"\nFirst half:";
  print (&head1);
  cout<<endl;

}
int main (void) {
  cll *head = NULL;
  insert (&head, 1);
  insert (&head, 2);
  insert (&head, 3);
  insert (&head, 4);
  insert (&head, 5);
  print (&head);
  splitCircularList (&head);
  return 0;
}
