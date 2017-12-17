/*
  Circular Linked List Program with following operations:
  1. Insertion at beginning  O(n)
  2. Insertion at last O(n)
  2. Deletion of last node   O(n)
  3. Printing   O(n)
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
  method to insert node at beginning
**/
void insertBegin (cll **head,  int data)  {
  cll *temp1 = NULL, *newNode = NULL, *temp2 = NULL;
  newNode = (cll*) malloc (sizeof(cll));
  if(!newNode)
    return;
  newNode->data = data;
  newNode->next = newNode;
  if(*head == NULL) {
    *head = newNode;
    //newNode->next = newNode;
    return;
  }
  newNode->next = *head;
  temp1 = *head;
  while(temp1->next != *head)
    temp1 = temp1->next;

  temp1->next = newNode;
  *head = newNode;
}

/*
  method to delete last node
**/
void deleteLastNode (cll **head) {
  cll *temp = *head, *curr = *head;
  while (temp->next != *head) {
    curr = temp;
    temp = temp->next;
  }
  curr->next = temp->next;
  free (temp);
  return;
}

/*
  method to insert node at last
**/
void insertLast (cll **head, int data) {
  cll *temp1 = *head, *newNode = NULL;
  newNode = (cll*) malloc (sizeof(cll));
  if(!newNode)
    return;
  newNode->data = data;
  newNode->next = newNode;
  if(*head == NULL) {
    *head = newNode;
    return;
  }
  while(temp1->next != *head) {
    temp1 = temp1->next;
  }

  newNode->next = temp1->next;
  temp1->next = newNode;
}

/*
  method to print circular linked list
**/
void printcll (cll **head) {
  cll *temp1=*head;
  do {
    cout<<temp1->data <<"->";
    temp1 = temp1->next;
  }while (temp1 != *head);
}

int main (void)  {
  cll *head = NULL;
  insertLast (&head, 1);
  insertLast (&head, 2);
  insertLast (&head, 3);
  insertBegin (&head, 5);
  insertBegin (&head, 6);
  insertBegin (&head, 7);
 // printf("After deletion\n", head->next->data);
  printcll (&head);
  deleteLastNode (&head);
  printf ("\nAfter deletion of last node\n");
  printcll (&head);
}
