/*
Problem 35: Split circular linked list into two parts
Time Complexity: O(n)
Space Complexity: O(1)
**/

#include<iostream>
#include<stdlib.h>

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
  cll *temp, *slow = *head, *fast = *head, *head1 = NULL, *head2 = NULL;
  // if odd nodes are there then fast->next points to last
  // else it points to second last
  while (fast->next != *head && fast->next->next != *head) {
    slow = slow->next;
    fast = fast->next->next;
  }
  if (fast->next->next == *head)
    fast = fast->next;
  cout<<"\nslow->data:"<<slow->data<<"\nfast->data:\n"<<fast->data;
  fast->next = slow->next;
  head1 = slow->next;
  print (&head1);

  slow->next = *head;
  head2 = *head;
  cout<<endl;
  print (&head2);

}
int main (void) {
  cll *head = NULL;
  insert(&head, 1);
  insert(&head, 2);
  insert(&head, 3);
  insert(&head, 4);
  print(&head);
  splitCircularList(&head);
  return 0;
}
