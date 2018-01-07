/*
Problem 49: Merge two sorted lists A(a1, a2..),  B (b1, b2..) as AB (a1, b1, a2, b2..)
Time Complexity: O (min (m, n))
Space Complexity: O(1)
**/

#include<iostream>
#include<stdlib.h>
using namespace std;

/*
defining the structure
**/
typedef struct sll{
  int data;
  struct sll *next;
}sll;

/*
Method to insert data into linked list
**/
void insert (sll **head, int data) {
  sll *newNode = NULL, *temp = *head;
  newNode = (sll*) malloc (sizeof(sll));
  newNode->data = data;
  newNode->next = NULL;
  if (*head == NULL) {
    *head = newNode;
    return;
  }
  while (temp->next != NULL)
    temp = temp->next;
  newNode->next = temp->next;
  temp->next = newNode;
}
void print (sll **head) {
  sll *temp = *head;
  while (temp != NULL) {
    cout<<temp->data<<"->";
    temp = temp->next;
  }
}

/*
Method to merge the linked list
**/
void merge (sll *head1, sll *head2) {
  sll *newNode = (sll*) malloc (sizeof(sll));
  if (!newNode)
    return;
  newNode->next = NULL;
  // 1. keep the first node address
  sll *temp = newNode;

  while (head1 != NULL && head2 != NULL) {
    temp->next = head1;
    head1 = head1->next;
    temp = temp->next;

    temp->next = head2;
    head2 = head2->next;
    temp = temp->next;
  }
  if (head1 != NULL)
    temp->next = head1;
  else
    temp->next = head2;

  temp = newNode->next;
  free (newNode);
  print (&temp);
}
int main (void) {
  sll *head1 = NULL, *head2 = NULL;
  insert (&head1, 1);
  insert (&head1, 3);
  insert (&head1, 5);
  cout<<"\nList 1:";
  print (&head1);
  insert (&head2, 2);
  insert (&head2, 4);
  insert (&head2, 6);
  insert (&head2, 7);
  cout<<"\nList 2:";
  print (&head2);
  cout<<"\nCombined List:";
  merge (head1, head2);
  cout<<endl;
  return 0;
}
