/*
Problem 45: Finding a modular node
Time Complexity: O(n)
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
Method to find modular node in linked list
**/
void modularNode (sll **head, int k) {
  int i = 1;
  sll *modular = NULL, *temp = *head;
  if(temp == NULL)
    return;
  while (temp != NULL) {
    if (i % k == 0) {
      modular = temp;
    }
    i++;
    temp = temp->next;
  }
  if (modular != NULL)
    cout<<"\nModular Node:"<<modular->data<<endl;
  else
    cout<<"\nModular Node doesn't exist"<<endl;
}

int main (void) {
  sll *head = NULL;
  insert (&head, 1);
  insert (&head, 2);
  insert (&head, 3);
  insert (&head, 4);
  insert (&head, 5);
  insert (&head, 6);
  insert (&head, 7);
  insert (&head, 8);
  insert (&head, 9);
  print (&head);
  modularNode (&head, 3);
  cout<<endl;
  return 0;
}
