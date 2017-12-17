/*
  Singly Linked List Program with following operations:
  1. Insertion  O(n)
  2. Deletion   O(n)
  3. Printing   O(n)
**/

#include<iostream>
#include<stdlib.h>

using namespace std;
/*
defining the structure
**/
typedef struct sll {
  int data;
  struct sll *next;
}sll;
/*
method for inserting node in linked list
**/
void insert (sll **head,  int position, int data) {
  sll *temp1 = NULL, *temp2 = NULL, *newNode = NULL;
  newNode = (sll*) malloc (sizeof(sll));
  if(!newNode) {
    cout<<"\nMemory error";
    return;
  }
  newNode->data = data;
  newNode->next = NULL;
  if (*head == NULL || position == 1) {
    newNode->next = *head;
    *head = newNode;
    return;
  } else {
    temp1 = *head;
    int pos = 1;
    while(temp1 != NULL && pos < position) {
      temp2 = temp1;
      temp1 = temp1->next;
      pos++;
    }

    temp2->next = newNode;
    newNode->next = temp1;
  }
}

/*
method for printing all nodes in linked list
**/
void printSinglyList (sll *head) {
  sll *temp = head;
  cout<<"\nElements in singly linked list:";
  while (temp != NULL) {
    cout<<temp->data<<"->";
    temp = temp->next;
  }
}

/*
method for deleting a node in linked list
**/
int deleteNode (sll **head, int position) {
  sll *temp1 = NULL, *temp2 = NULL;
  if (position == 1) {
    temp1 = *head;
    *head = (*head) ->next;
    free(temp1);
    return 1;
  }
  int pos = 1;
  temp1 = *head;
  while(temp1 != NULL && pos < position) {
    pos++;
    temp2=temp1;
    temp1 = temp1->next;
  }
  if(temp1 == NULL)
    cout<<"\nPosition doesn't exist";
  else {
    temp2->next = temp1->next;
    return 1;
  }
  return 0;
}


int main (void) {
  sll *head = NULL;
  insert (&head,6,1);
  insert (&head,1,2);
  insert (&head,4,3);
  insert (&head,2,4);
  insert (&head,5,5);
  insert (&head,3,6);

  printSinglyList (head);


  cout<<"\nAfter deleting 3rd element:";
  deleteNode (&head,3);
  printSinglyList (head);
  printf ("\n");
  return 0;
}
